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


    // auto it1 = st.begin();
    // it1++;

    // auto it2 = st.end();
    // it2--;

    // st.erase(it1,it2);
    // for(auto i: st){
    //     cout<<i<<" ";
    // }


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
}


int main(){

    //explainPair();
    //explainvector();
    //explainlist();
    //explainStack();
    //explainPQ();
    explainset();
    return 0;
}