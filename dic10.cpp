// dic10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;



vector<pair<string, int >>  histogram(vector<string> arr) {

    vector<pair <string, int>> temp;

    for (int i = 0; i < arr.size(); ++i) {
        int count = 1;
        string word = arr[i];
        for (int j = arr.size() - 1; j > i; --j) {

            if (arr[j] == word) {
                count++;
                arr.erase(arr.begin() + j);

            }
            


        }
        temp.insert(temp.end(), { word,count });



   }




    return temp;

}




vector<pair <string, vector<string >    >   >  group(vector<pair <string, string >> temp) {

    vector<pair <string, vector<string >    >   > arr;
    for (int i = 0; i < temp.size(); ++i) {
        vector<string > prod = {temp[i].first};
        string used = temp[i].second;
        for (int j = temp.size() - 1; j > i; --j) {
            if (used == temp[j].second) {
                prod.insert(prod.end(), temp[j].first);
                temp.erase(temp.begin() + j);
            }





        }
        arr.insert(arr.end(), { used , prod });



    }


    return arr;


}

void outprod(vector< pair <string, vector<string > >> arr) {

    for (int i = 0; i < arr.size(); ++i) {


        std::cout << "Prod : " << arr[i].first<<" elem : ";
        for (int j = 0; j < arr[i].second.size(); ++j) {
            std::cout << arr[i].second[j] <<"  ";
        }
        cout << endl;





    }


    return;


}












void out(vector<pair<string, int >> arr) {
    for(int i=0;i<arr.size();++i){
        std::cout << "string " << arr[i].first<< " int " << arr[i].second<<endl;

    
    
    
    }
    return;
 }

void outint(vector<pair<int, int >> arr) {
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << "fst " << arr[i].first << " snd " << arr[i].second << endl;




    }
    return;
}




string stredit(string arr, vector<pair<char, char >> change) {
    
    for (int i = 0; i < change.size(); ++i) {

        for (int j = 0; j < arr.size(); ++j) {

            if (arr[j] == change[i].first) {
                arr[j] = change[i].second;
            }


        }




    }

    return arr;





}



// znam che moje za vreme O(n * logn ) kato napravia dvoichno tursene no ne mi se zanimavashe

vector<pair<int, int > > cursum(int target, vector<int> arr) {


    vector<pair<int, int > > temp;
    int size = arr.size();
    for (int i = 0; i < size; ++i) {
        for (int j = i+1; j < arr.size(); ++j) {
            if (arr[i] + arr[j] == target) temp.insert(temp.end(), { i,j });
                



        }


    }
    return temp;


}



vector<pair<int, int > > sim ( vector<pair <int ,int> >  arr) {


    vector<pair<int, int > > temp;
    int size = arr.size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < arr.size(); ++j) {
            if (arr[i].first == arr[j].second && arr[i].second == arr[j].first) temp.insert(temp.end(), arr[i]);




        }


    }
    return temp;


}



vector<int > helper(char cur, string arr) {

    vector<int > tr;
    for (int i = 0; i < arr.size(); ++i) {
        if (cur == arr[i]) {
            tr.insert(tr.end(), i);
        }

    }
    return tr;





}


bool isomor(string s1, string s2) {

    if (s1.size() != s2.size()) return false;


    for (int i = 0; i < s1.size(); ++i) {


        if (helper(s1[i], s1) != helper(s2[i], s2)) return false;




    }
    return true;




}














int main() {
    /* 1 zad 
    vector<string> arr = { "apple", "banana", "apple", "orange", "banana", "apple" };
    vector<pair<string, int >>  temp = histogram(arr);

    out(temp);
    */
    /* 2 zad 
    vector< pair < string, string >   > arr = { {"apple", "fruit"}, {"carrot", "vegetable"}, {"banana", "fruit"}, {"broccoli", "vegetable"} };
    vector<pair <string, vector<string >    >   >  temp = group(arr);
    outprod(temp);
    */
    /* 3 zad 
    string arr = "hello world";
    vector<pair<char, char >> change = { {'h','H'}, {'e', '3'}, {'o','0'} };
    cout << stredit(arr, change );
    */
    /* 4 zad 
    vector<int> arr = { 8,7,2,5,3,1 };

    vector<pair<int, int > >  temp = cursum(10, arr);
    outint(temp);
    */
    /* 5 zad 
    vector<pair<int, int > >  temp = { {3,4} , {1,2} , {5,2} , {7,10 } , {4,3} , {2,5} };
    vector<pair<int, int > > arr = sim(temp);
    outint(arr);
    */
    string s1 = "acab";
    string s2 = "xcxy";
    string s3 = "accb";
    
    cout << isomor(s1, s2) << endl;
    cout << isomor(s2, s3);






}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
