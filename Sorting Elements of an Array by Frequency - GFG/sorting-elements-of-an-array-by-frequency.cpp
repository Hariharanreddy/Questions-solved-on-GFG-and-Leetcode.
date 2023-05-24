#include <bits/stdc++.h>
using namespace std;

bool sortcus(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    
    return a.second > b.second;
}

vector<int> sortEle(int arr[],int n){
    
    unordered_map<int, int> ump;
    vector<pair<int, int>> vec;
    vector<int> ans;
    
    //Storing the frequency of the array in map
    for(int i=0 ; i<n ; i++){
        ump[arr[i]]++;
    }
    
    //Store all the mp pairs in vector 
    for(auto it = ump.begin() ; it != ump.end() ; it++){
        vec.push_back({it->first, it->second});
    }
    
    //Sort the vector by making custom rules
    sort(vec.begin(), vec.end(), sortcus);
    
    //populate the sorted vector inside ans vector
    for(int i=0 ; i < vec.size() ; i++){
        
        while(vec[i].second > 0){
            ans.push_back(vec[i].first);
            vec[i].second--;
        }
        
    }
    
    return ans;
}


int main() {
	
	int t = 0; 
	cin>>t;
	
	while(t > 0){
	    
	    int size = 0;
	    cin>>size;
	    
	    int arr[size];
	    
	    for(int i=0 ; i<size ; i++){
	        cin>>arr[i];
	    }
	    
	    vector<int> v;
	    
	    v = sortEle(arr, size);
	    
	    for(auto el : v){
	        cout<<el<<" ";
	    }
	    
	    cout<<endl;
	    
	    t--;
	}
	
	return 0;
}