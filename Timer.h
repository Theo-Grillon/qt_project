//
// Created by Théo on 05/05/2020.
//

#ifndef QT_PROJECT_TIMER_H
#define QT_PROJECT_TIMER_H


class Timer {
private:
    int Time=0;
public:
    int getTime(){return Time;}
    void increase(){Time+=30;}
};


#endif //QT_PROJECT_TIMER_H
