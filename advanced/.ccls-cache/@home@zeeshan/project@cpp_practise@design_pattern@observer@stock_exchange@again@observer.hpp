

#pragma once

#include <vector>
#include <memory>
#include <algorithm>

#include <iostream>
class observer
{
	public:
		virtual void update() = 0;
		bool exist() { return _exist; }
		virtual ~observer() { _exist = false;}
	private:
		bool _exist = true;
};


class observable
{
	public:
		void add_observer(std::weak_ptr<observer> o)
		{
			observers.push_back(o);
		}
		void remove_observer(std::weak_ptr<observer> o)
		{
			observers.erase(find_if(std::begin(observers), std::end(observers), 
						[o](std::weak_ptr<observer> a){return a.lock().get() == o.lock().get();}));
		}
		void notify()
		{
			std::cout <<"count: " << observers.size() << "\n";
			for(auto x = observers.begin(); x!=observers.end(); )
			{
				if((*x).expired())
					observers.erase(x);
				else
				{
					((*x).lock())->update();
					++x;
				}
			}

		}

	private:
		std::vector<std::weak_ptr<observer>>observers;
};
