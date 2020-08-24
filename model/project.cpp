#include "project.h"

Project::Project(std::string p_name) : m_name(p_name) {}

Project::~Project() {
    if(! m_lists.empty())
        for(std::map<unsigned short int,List*>::iterator i=m_lists.begin(); i!=m_lists.end(); i++)
            delete i->second;
}

void Project::addList(List *p_list) {
    std::map<unsigned short int,List*>::value_type l(p_list->getId(),p_list);
    m_lists.insert(l);
}

void Project::removeList(unsigned short int idList) {

    // Se p_list ha figli -> eliminali
    delete m_lists.at(idList);

    // Elimina da m_listOrder
    for(std::vector<unsigned short int>::iterator i = m_listsOrder.begin(); i != m_listsOrder.end(); i++)
        if (*i == idList) {
            m_listsOrder.erase(i);
            i = m_listsOrder.end();
        }
}

void Project::setName(const std::string& p_name) { m_name = p_name; }

void Project::setListName(const unsigned short int idList, const std::string& p_name) {
    getList(idList)->setName(p_name);
}

std::string Project::getName() const { return m_name; }

//std::vector<List *> Project::getLists() const { return m_lists; }

List *Project::getList(const unsigned short int idList) const {
    return m_lists.at(idList);
}

void Project::addNewTask(const unsigned short int idList, AbsTask* p_task) {
    m_lists.at(idList)->addTask(p_task);
}

void Project::addNewList() {
    List* newList = new List();
    std::map<unsigned short int,List*>::value_type l(newList->getId(),newList);
    m_lists.insert(l);
}

void Project::ConvertToPriority(const unsigned short int idList, const unsigned short int idTask) {
    List* l = m_lists.at(idList);
    AbsTask* t = l->getTask(idTask);

    TaskContainer* tCont = dynamic_cast<TaskContainer*>(t);
    AbsTask* tNew;
    if(tCont) {
        tNew = new TaskPriorityContainer(t->getLabel(),t->getDesc(),t->getList(),t->getParent());
        dynamic_cast<TaskContainer*>(tNew)->addChildList(tCont->getChilds());
    } else
        tNew = new TaskPriority(t->getLabel(),t->getDesc(),t->getList(),t->getParent());
    l->updateTask(idTask,tNew);
    delete t;
}


/*
template <class T>
QJsonDocument Project<T>::toJson() const {
	QJsonDocument doc;
	QJsonObject obj;
	obj.insert("name", m_name);
	QJsonArray tasks;
	for (auto it = m_tasks.begin(); it != m_tasks.end(); it++) {
		tasks.append(it->toJson());
	}
	obj.insert("tasks", tasks);
	doc.setArray(tasks);
}
*/
