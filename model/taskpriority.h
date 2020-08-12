#ifndef TASKPRIORITY_H
#define TASKPRIORITY_H

#include "abstask.h"

template <class T>
class TaskPriority : virtual public AbsTask {
private:
    T m_priority;
public:
    TaskPriority(T p_priority, const std::string p_label =std::string(), const std::string p_desc =std::string(), std::string* p_list =nullptr, AbsTask* p_parent =nullptr);

    T                               getPriority() const;
    void                            setPriority(T);
};



template<class T>
TaskPriority<T>::TaskPriority(T p_priority, const std::string p_label, const std::string p_desc, std::string *p_list, AbsTask *p_parent)
    :   AbsTask(p_label,p_desc,p_list,p_parent), m_priority(p_priority) {}

template<class T>
T TaskPriority<T>::getPriority() const {
    return m_priority;
}

template<class T>
void TaskPriority<T>::setPriority(T p_priority) {
    m_priority = p_priority;
}

#endif // TASKPRIORITY_H
