


/*
arg --> 1 string
return -> reverse of string

Example:
"this is a boy. Boy is happy."

return:
"Happy is boy boy. a is this."

Consatatint: Positon of full stop should not change.

*/


//std::list --. linkedind
std::string reverse(std::string const & str)
{

    auto stop = str.begin();
    while(stop != str.end())
    {
        auto stop = std::find(str.begin(), str.end(), ". ");
        auto counts = std::count(str.begin(), stop, " ");
        pos.push_back(counts);
    }

    std::vector<int>pos;
    int word = 0;
    for(int i=0; i<str.size(); ++i)
    {
        if(str == ' ')
            ++word;
        else if(str[i] == '.')
        {
            pos.push_back(++word);
            if(i != str.size()-1 and str[i+1] ==' ')
                ++i;
        }
    }

    //pos --> 4, 7
    //"yppah si yob boy. a is this."
    str.insert(17, '.');

}
