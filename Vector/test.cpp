#include<iostream>
#include<vector>

using namespace std;

int main(int argc, const char** argv) {
    vector<int> ret={1,2,3,4,5};
    cout<<ret.size()<<endl;
    for(int i=0;i<ret.size();++i)
    {
        cout<<ret[i]<<" ";
    }
    cout<<endl;
    ret.push_back(1024);
    cout<<ret.size()<<endl;
    for(int i=0;i<ret.size();++i)
    {
        cout<<ret[i]<<" ";
    }
    cout<<endl;
    
    cout<<ret[5]<<endl;
    return 0;
}
