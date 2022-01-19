

#pragma once

#include <set>
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
		void add_observer(observer & o)
		{
			observers.insert(&o);
		}
		void remove_observer(observer & o)
		{
			observers.erase(&o);
		}
		void notify()
		{
			std::cout <<"count: " << observers.size() << "\n";
			for(auto x : observers)
			{
				if(!x->exist())
				{
					std::cout << "here\n";
					observers.erase(x);
				}
				else
					x->update();
			}
		}

	private:
		std::set<observer*>observers;
};
