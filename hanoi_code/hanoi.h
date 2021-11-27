//
//  hanoi.h
//  hanoi_code
//
//  Created by line.ash on 2021/11/25.
//

#ifndef hanoi_h
#define hanoi_h

#include <iostream>
#include <bangtal>
using namespace bangtal;

//막대 클래스
class hanoi_Bar{
public:
    int index=-1;
    hanoi_Bar(int i, ScenePtr scene):index(i){
        char buf[20];
        sprintf(buf, "hanoi_%d.png", i);
        Object::create(buf, scene, 240, 220 + 50*i); //막대는 모두 첫번째 타워에서 생성된다.
    };
};

//타워 클래스
class hanoi_Tower{
public:
    hanoi_Bar* slot[4]={nullptr}; //타워는 막대 소유 유무를 알기 위해 막대포인터를 가진다.
    int tower_top=-1; //타워에 막대가 몇층까지 있는지.
    int tower_index=-1; //타워의 맨 위 막대 크기.
    
    hanoi_Tower()
    {
    };
    
    int check_top() //타워에 막대가 몇층까지 있는지 체크합니다.
    {
        tower_top=-1; //초기화
        for(int i=0; i<4; i++)
        {
            if(slot[i]!=nullptr)
                tower_top = i;
        }
        return tower_top;
    }
    
    int check_tower_index() //맨 위 막대의 크기를 확인합니다.
    {
        tower_index=-1; //초기화
        tower_index=slot[check_top()]->index;
        return tower_index;
    }
};

#endif /* hanoi_h */
