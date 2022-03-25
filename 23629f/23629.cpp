// 23629, Gold 5, 이 얼마나 끔찍하고 무시무시한 수식이니 (문자열)
// https://www.acmicpc.net/problem/23629
#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <cctype>

using namespace std;

long long operate(long long sum, long long num, char xx)
{
    if (xx=='=')
        return sum;
    else if (xx=='+')
        return sum+=num;
    else if (xx=='-')
        return sum-=num;
    else if (xx=='x')
        return sum*=num;
    else if (xx=='/')
        if (num==0){
            cout << "Madness!";
            exit(0);
        }
        return sum/=num;
}

int solve(string s1)
{
    vector<long long> v;
    vector<string> nums;
    vector<char> ex;
    if (s1[s1.length()-1]!='='){
        cout << "Madness!";
        exit(1);
    }
    v.push_back(-1);
    s1 = regex_replace(s1,regex("ZERO"),"0");
    s1 = regex_replace(s1,regex("ONE"),"1");
    s1 = regex_replace(s1,regex("TWO"),"2");
    s1 = regex_replace(s1,regex("THREE"),"3");
    s1 = regex_replace(s1,regex("FOUR"),"4");
    s1 = regex_replace(s1,regex("FIVE"),"5");
    s1 = regex_replace(s1,regex("SIX"),"6");
    s1 = regex_replace(s1,regex("SEVEN"),"7");
    s1 = regex_replace(s1,regex("EIGHT"),"8");
    s1 = regex_replace(s1,regex("NINE"),"9");

    for (int i=0; i<s1.length();i++){
        if (s1[i]=='x') continue;
        if (isalpha(s1[i])){
            cout << "Madness!";
            exit(0);
        }
    }

    string og = s1;
    //cout << og << endl;
    ex.push_back('+');
    for (int i=0 ; i<s1.length();i++){
        if (s1[i]=='+'||s1[i]=='-'||s1[i]=='x'||s1[i]=='/'||s1[i]=='='){
            ex.push_back(s1[i]);
            v.push_back(i);
        }
    }
    // for (auto loop : ex){
    //     cout << loop << endl;
    // }

    for (int i=0 ; i< v.size()-1 ; i++){
        string temp = s1.substr(v[i]+1,v[i+1]-v[i]-1);
        nums.push_back(temp);
    }
    vector<int> si; // 정수로 변환한 문자열 담아놓는 곳.
    for (auto loop : nums){
        try {
        long long temp = stoi(loop);
        si.push_back(temp);
        } catch (const exception& expn){
            cout << "Madness!\n";
            return 0;
        }
    }

    long long sum=0;
    for (int i=0 ; i<si.size();i++){
        sum = operate(sum, si[i], ex[i]);
    }
    string tostring = to_string(sum);

    tostring = regex_replace(tostring,regex("0"),"ZERO");
    tostring = regex_replace(tostring,regex("1"),"ONE");
    tostring = regex_replace(tostring,regex("2"),"TWO");
    tostring = regex_replace(tostring,regex("3"),"THREE");
    tostring = regex_replace(tostring,regex("4"),"FOUR");
    tostring = regex_replace(tostring,regex("5"),"FIVE");
    tostring = regex_replace(tostring,regex("6"),"SIX");
    tostring = regex_replace(tostring,regex("7"),"SEVEN");
    tostring = regex_replace(tostring,regex("8"),"EIGHT");
    tostring = regex_replace(tostring,regex("9"),"NINE");

    cout << og << endl;
    cout << tostring << endl;

    return 1;
}

int main()
{
    string s1;

    cin >> s1;

    int t = solve(s1);

    return 0;
}