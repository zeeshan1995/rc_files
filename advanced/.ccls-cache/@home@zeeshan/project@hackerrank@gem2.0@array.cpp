#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the arrayMerging function below.
 */

std::vector<long long> fac;
int arrayMerging(vector<int> m) {
    if(m.size() < 2)
        return 1;
}

int main()
{
freopen("input.txt", "r", stdin);
    ofstream fout(getenv("OUTPUT_PATH"));

    int m_count;
    cin >> m_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string m_temp_temp;
    getline(cin, m_temp_temp);

    vector<string> m_temp = split_string(m_temp_temp);

    vector<int> m(m_count);

    for (int m_itr = 0; m_itr < m_count; m_itr++) {
        int m_item = stoi(m_temp[m_itr]);

        m[m_itr] = m_item;
    }

    fac.push_back(1);
    fac.push_back(1);
    for(int i=2; i<608; ++i)
        fac.push_back(i * fac.back());

    int result = arrayMerging(m);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
