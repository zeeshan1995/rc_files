

#include "driver.hpp"
#include "db_operations.hpp"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>


namespace interact{
	int globalMenu()
	{
		std::cout << "Choose operation:\n" <<
			"1.Select\n2.Insert\n3.Update\n4.Delete\n5.Quit\n";
		int choice;
		std::cin >> choice;
		std::cin.ignore();
		return choice;
	}

	std::map<std::string, std::string> getConfig(boost::property_tree::ptree const& pt)
	{
		std::map<std::string, std::string>conf;
		using boost::property_tree::ptree;
		ptree::const_iterator end = pt.end();
		for (ptree::const_iterator it = pt.begin(); it != end; ++it)
			conf[it->first]=it->second.get_value<std::string>();
		return conf;
	}

	void interact(std::string const & file)
	{
		boost::property_tree::ptree pt;
		boost::property_tree::read_json(file, pt);
		auto conf = getConfig(pt);

		driver::Driver d; 
		std::cout << "Connecting to database at " << conf["host"] << " as " << conf["user"] << "\n"; 
		driver::Connection con(d, conf["host"], conf["user"], conf["pass"]);
		std::cout << "Setting schema to " << conf["schema"] << "\n";
		con.setSchema(conf["schema"]);

		auto choice = globalMenu();

		while(choice!=5)
		{
			if(choice==1)
			{
				auto result = db_ops::select(con,conf["def_table"]);
				result.print();
				std::cout <<"\n----------\n";
			}
			else
			{
				switch (choice)
				{
					case 2: std::cout << db_ops::insert(con,conf["def_table"]) 
							<<" rows inserted.\n---------\n"; 
							break;
					case 3: std::cout << db_ops::update(con,conf["def_table"]) 
							<< " rows updated.\n---------\n"; 
							break;
					case 4: std::cout << db_ops::del(con,conf["def_table"]) 
							<< " rows deleted.\n--------\n"; 
							break;
				}
			}

			choice = globalMenu();
		}
	}
}
