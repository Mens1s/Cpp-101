#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Set{
    private:
        
    public:
        virtual bool add(T obj) = 0;
        virtual bool contains(T obj) = 0;
        virtual void intersection(T obj){};
        virtual int size() = 0;
};

template<typename T>
class SetA : public Set<T>{
    private:
        int size_;
        vector<T> data;
    public:
        SetA(){
            size_ = 0;
        }

        int size(){ return size_; };

        bool contains(T obj){
            for(int idx = 0; idx < size_; idx++)
                if(data[idx] == obj)
                    return true;
            return false;
        };

        bool add(T obj){
            if( contains(obj) )
                return false;
            data.push_back(obj);
            size_++;
            return true;
        };

        SetA intersection(SetA<T> obj){
            SetA result;

            for(int idx = 0; idx < size(); idx++)
                if(obj.contains(data[idx]))
                    result.add(data[idx]);
            
            return result;
        }

        void print(){
            for(auto t : data)
                cout << "t: " << t;
            cout << endl; 
        }
};

template<typename T>
class SetC : public Set<T>{
    private:
        T * data;
        int size_;
        int cap_;
    public:
        SetC(){
            size_ = 0;
            cap_  = 4;
            data = new T[cap_];
        }
        bool add(T obj){
            if( contains(obj) )
                return false;

            if(size_ + 1 == cap_)
            {
                T * temp = new T[cap_];

                for(int idx = 0; idx < cap_; idx++)
                    temp[idx] = data[idx];

                cap_ *= 2;

                data = new T[cap_];

                for(int idx = 0; idx < cap_; idx++)
                    data[idx] = temp[idx];
            }
            
            data[size_] = obj;
            size_++;

            return true;
        };
        bool contains(T obj){
            for(int idx = 0; idx < size_; idx++)
                if(data[idx] == obj)
                    return true;
            return false;
        };
        SetC intersection(SetC<T> obj){
            SetC result;

            for(int idx = 0; idx < size(); idx++)
                if(obj.contains(data[idx]))
                    result.add(data[idx]);
            
            return result;
        };
        int size(){return size_;};

        void print(){
            for(int idx = 0; idx < size_; idx++)
                cout << data[idx]  <<" : ";
            cout << endl; 
        }
};

int main(){
    SetA<int> test;
    SetA<int> test1;
    test.add(10);
    test.add(20);
    test.add(30);
    test.add(10);
    test.print();

    test1.add(10);
    test1.add(321);
    test1.add(32);
    test1.add(12);
    test1.print();

    SetA<int> test0 = test.intersection(test1);
    test0.print();

    cout << endl << "heyy" << endl;
    SetC<int> test2;
    SetC<int> test3;
    test2.add(10);
    test2.add(20);
    test2.add(30);
    test2.add(10);
    test2.print();

    test3.add(10);
    test3.add(321);
    test3.add(32);
    test3.add(12);
    test3.print();

    SetC<int> test4 = test2.intersection(test3);
    test4.print();

    return 0;
}