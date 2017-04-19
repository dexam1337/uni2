/*
 * PrioQueue.h
 *
 *  Created on: 04.04.2017
 *      Author: sebastian
 */

#include <vector>
#include <iostream>

using namespace std;

#ifndef PRIOQUEUE_H_
#define PRIOQUEUE_H_

template<class T>
class PrioQueue
{
private:
    vector<T> m_obj;

public:

    void push(T newObj)
    {   if(m_obj.size() == 0)
         m_obj.push_back(newObj);
    else
        for(int i = 0; i<m_obj.size();i++){
            if(m_obj.at(i).getPrio()>newObj.getPrio()){
                m_obj.insert(m_obj.begin()+i,newObj);
                break;
            }
            if(m_obj.size()-1==i){
                m_obj.push_back(newObj);
                break;
            }
            
        }
       
    }

    T pop()
    {
        cout<<m_obj.size()<<endl;
        if(m_obj.size() == 0){
            throw runtime_error("kein obj");
            
        }
        T obj = m_obj.front();
        m_obj.erase(m_obj.begin());
        return obj;
    }
};



#endif /* PRIOQUEUE_H_ */