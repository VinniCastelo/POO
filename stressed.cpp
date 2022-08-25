#include <iostream>
#include <vector>
using namespace std;

//BLOCO 1 - FIND

// in-----------------------------------------------------------------------------------------------
bool in(vector<int> n, int value){
    for(auto elem : n)
        if(elem == value)
            return true;
    return false;
}
// index_of-----------------------------------------------------------------------------------------------
int index_of(vector<int> n, int value)
{
    for(int i = 0; i < n.size(); i++)
        if(n[i] == value)
            return i;
    return -1;
}
// find_if-----------------------------------------------------------------------------------------------
int find_if(vector<int> n, int value)
{
    for(int i = 0; i < n.size(); i++)
        if(n[i] > 0)
            return i;
    return -1;
}
// min_element-----------------------------------------------------------------------------------------------
int min_element(vector<int> n)
{
    int pos_min = { 0 };
    for(int i = 0; i < n.size(); i++)
        if(n[i] < n[pos_min])
            pos_min = i;
    return pos_min;
}
//find_min_if-----------------------------------------------------------------------------------------------
int find_min_if(vector<int> n){
    int pos_men = { -1 };
    for(int i = 0; i < n.size(); i++)
        if(n[i] > 0 && (n[pos_men] > n[i] || pos_men == -1))
        pos_men = i;
    return pos_men;
}
// ====================================================================================
// BLOCO 1 - COUNT

// count --------------------------------------------------------------
int count(vector<int> n, int value)
{
    int appeared = { -1 };
    for(auto elem : n)
        if(elem == value){
            appeared++;
            if(appeared == 0)
                appeared++;
        }
    return appeared;
}

// average --------------------------------------------------------------
float average(vector<int> n) {
    int all = { 0 };
    for (auto element : n)
        all = all + abs(element);
    float output{all / (float)n.size()};
    return output;
}

// half_compares --------------------------------------------------------------
string half_compare(vector<int> n) {
    auto met = (int)n.size() / 2;
    int m1{0}, m2{0};
    for(auto i = 0; i < met; i++)
        m1 = m1 + abs(n[i]);
    for(auto i = met; i < (int)n.size(); i++)
        m2 = m2 + abs(n[i]);
    if(m1 > m2)
        return "first";
    if(m1 < m2)
        return "second";
    return "draw";
}

//more_men_or_women --------------------------------------------------------------
string more_men_or_women(vector<int> n) {
    int men = { 0 }, women = { 0 };
    for(auto elem : n)
        if(elem > 0)
            men++;
        else 
            women++;
    if(men > women)
        return "men";
    if(men < women)
        return "women";
    return "draw";
}

//sex_battle -----------------------------------------------------------------------
string sex_battle(vector<int> n) {
    int men{0}, women{0};
    int countMen{0}, countWomen{0};
    for (auto element : n) {
        if (element > 0) {
            countMen++;
            men += element;
        }
        else {
            countWomen++;
            women = women + abs(element);
        }
    }
    if (men / countMen > women / countWomen)
        return "men";
    if (men / countMen < women / countWomen)
        return "women";
    return "draw";
}

int main() {

    cout << "FIND ===============================================================" << endl;
    cout << in({-1, -50, -99}, -99) << endl; //-> TRUE
    cout << index_of({-1, -50, -1, -99}, -99) << endl; //-> 3
    cout << find_if({-1, -50, -1, -99}, 10) << endl; //-> -1
    cout << min_element({5, 3, -1, -50, -1, -99}) << endl; //-> 5
    cout << find_min_if({-1, -50, -1, -99, -444}) << endl; //-> -1

    cout << "COUNT ==============================================================" << endl;

    cout << count({-1, -50, -1, -99}, -1) << endl; //-> 2
    cout << average({1, 2, 3, -4, -5, -6}) << endl; //-> 3.5
    cout << half_compare({ 50, -98,  2, -50,  -1, -99}) << endl; //-> DRAW
    cout << more_men_or_women({5, 3, 1, -50, -1, -99}) << endl; //-> DRAW
    cout << sex_battle({50, 98, 2, -50, -1, 9991}) << endl; // MEN
    return 0;
}
