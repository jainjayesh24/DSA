#include<bits/stdc++.h>
using namespace std;

void explainPair() {
    pair<int,int> pr1 = {2,8};
    pair<int,char> pr2 = make_pair(30,'p');
    cout<<pr1.first<<" "<<pr1.second<<endl;
    cout<<pr2.first<<" "<<pr2.second<<endl;
}
void explainvector(){
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(-1);
    vec.emplace_back(3);

    //iterator
    vector<int>::iterator beginitr = vec.begin();
    auto enditr = vec.end();

    for(auto i = beginitr;i<enditr;i++){
        cout<<*i<<" ";
    }
    cout<<endl;

    for(auto i:vec){
        cout<<i<<" ";
    }
    cout<<endl;


    //Reverse iterator
    auto rbegin = vec.rbegin();
    auto rend = vec.rend();


    //Backward Printing of vector  
    for(auto i=rbegin;i<rend;i++){
        cout<<*i<<" ";
    }
    cout<<endl;

    //Size of vector
    //cout<< vec.size() <<endl;

    //Duplicate vector
    vector<int> dupl(vec.begin()+1,vec.end()-1);
    for(auto i:dupl){
        cout<<i<<" ";
    }
    cout<<endl;


    //vec.clear() -> deleting all elements from vector
    //erase

    cout<<"Erase function"<<endl;
    for(auto i: vec){
        cout<<i<<" ";
    }
    cout<<endl;

    vec.erase(vec.begin()+1,vec.end()-1);
    for(auto i: vec){
        cout<<i<<" ";
    }
    cout<<endl;


    //swap
    vector<int> vec1 = {7,4};
    vector<int> vec2 = {3,5,7};
    swap(vec1,vec2);

    for(auto i: vec2){
    cout<<i<<" ";
}
}
void explainlist(){


    list<int> ls = {6,7};
    ls.push_front(56);
    for(auto i: ls){
        cout<<i<<" ";
    }

    // All other operations same as of vector

}
void explainStack(){
    stack<int> st;
    st.push(1);
    st.push(7);
    st.push(71);
    st.push(85);

    //No iterator

    cout<<st.top()<<endl;

    while(st.empty()==false){
        cout<<st.top()<<" ";
        st.pop();
    }
}
void explainPQ(){
    // Stores the highest element at the top --> underneath Heaps are implemented
    //Max heap
    //priority_queue<int> pq;

    //Min heap
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(71);
    pq.push(5);
    pq.push(90);
    pq.push(34);

    while(pq.empty() == false){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
void explainset() {
    // Unique elements (ascending order)
    //iterator support
    set<int> st;
    st.insert(4);
    st.insert(21);
    st.insert(21);
    st.insert(21);
    st.insert(21);
    st.insert(2);
    st.insert(12);
    st.insert(90);

    for(auto i: st){
        cout<<i<<" ";
    }
    cout<<endl;
    auto it = st.find(121);
    if(it != st.end()){
        cout<<*it;
    }


    auto it1 = st.begin();
    it1++;

    auto it2 = st.end();
    it2--;

    st.erase(it1,it2);
    for(auto i: st){
        cout<<i<<" ";
    }


    //lowerbound
    //returns an interator  that points to an element
    // that is>=number given 

    auto it1 = st.lower_bound(21);
    if(it1 == st.end()){
        cout<<"end";
    }else{
        cout<<*it1<<endl;
    }

    //upperbound
    // returns an iterator points to an element
    // that is > number given
    auto it2 = st.upper_bound(90);
    if(it2 == st.end()){
        cout<<"end";
    }else{
        cout<<*it2<<endl;
    }

    //Unorder set -> all operations same as set elements are stored in sequnce which they are inserted
    //Why? --> Better time complexity o(1)
    // No lowebound and upperbound
}
void explainmultiset(){
    multiset<int> ms;
    ms.insert(4);
    ms.insert(4);
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(90);
    ms.insert(89);
    for(auto i : ms){
        cout<<i<<" ";
    }cout<<endl;

    // Delete all occurence 
    ms.erase(4);
    for(auto i : ms){
        cout<<i<<" ";
    }cout<<endl;

    //Delete single occurence
    ms.erase(ms.find(1));
    for(auto i : ms){
        cout<<i<<" ";
    }cout<<endl;

    cout<<ms.count(1);


}
void explainmap(){
    map<int, string> mpp;
    // elements stored according to keys(ascending order)
    mpp[1] = 'a';
    mpp[2] = 'b';
    mpp[3] = 'c';
    mpp.insert({4,"d"});

    // key value pair stored as --> pair 
    // for(auto it : mpp){
    //     cout<<it.first<<"->"<<it.second<<endl;
    // }

    auto it = mpp.find(2);
    if(it == mpp.end()){
        cout<<"element not found";
    }else{
        cout<<(*it).first<<"->"<<(*it).second<<endl;
    }

    //lowerbound & upperbound
    //Unorderedmap 

    // Multimap allows to store duplicate values
}
void explainsort(){
    int arr[6] = {6,1,9,2,8,0};
    // sort all the elements present in array 
    sort(arr,arr+6);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    
    // All elements will be sorted except first and last
    sort(arr+1,arr+5);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;


    vector<int> vec = {6,1,9,2,8,0};
    sort(vec.begin()+1,vec.begin()+4);  // sort(a,b) -> till b-1 
    for(auto it : vec){
        cout<<it<<" ";
    }

}
void explainaccumulate(){
    int arr[6] = {6,1,9,2,8,0};
    cout<<accumulate(arr+1,arr+4,0)<<endl;
}
void explainpermutation(){
    // next permutation in sorted order
    string str1 = "abcd";
    string str2 = "dbca";
    do{
        cout<<str1<<" ";
    }while(next_permutation(str1.begin(),str1.end()));
    cout<<endl;

    do{
        cout<<str2<<endl;
    }while(next_permutation(str2.begin(),str2.end()));
}
void explainMaxMin(){
    int arr[6] = {6,1,9,2,8,0};
    auto itr1 = max_element(arr,arr+6);
    auto itr2 = min_element(arr,arr+6);
    cout<<*itr1<<endl;
    cout<<*itr2<<endl;

}


int main(){
    explainPair();
    explainvector();
    explainlist();
    explainStack();
    explainPQ();
    explainset();
    explainmultiset();
    explainmap();
    explainsort();
    explainaccumulate();
    explainpermutation();
    explainMaxMin();
    return 0;
}