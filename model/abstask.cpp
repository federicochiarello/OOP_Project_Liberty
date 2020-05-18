#include "abstask.h"

AbsTask::AbsTask(std::string* p_list, const std::string p_label, const std::string p_desc, AbsTask* p_parent) :
	m_parent(p_parent),
	m_eta(time(nullptr)),
	m_list(p_list),
	m_label(p_label),
	m_desc(p_desc) {}

AbsTask::AbsTask(const AbsTask& p_task, AbsTask* p_parent) :
	m_parent(p_parent),
	m_eta(time(0)),
	m_list(p_task.m_list),
	m_label(p_task.m_label),
	m_desc(p_task.m_desc) {}

AbsTask::AbsTask(const QJsonObject& p_obj, AbsTask* p_parent) :
	m_parent(p_parent),
	m_eta(p_obj.value("eta").toInt()),
	m_list(),
	m_label(p_obj.value("label").toString().toStdString()),
	m_desc(p_obj.value("desc").toString().toStdString()) {

}

std::string		AbsTask::getLabel() const { return m_label; }

std::string		AbsTask::getDesc() const { return m_desc; }

std::time_t		AbsTask::getEta() const { return m_eta; }

AbsTask*		AbsTask::getParent() const { return m_parent; }

std::string*	AbsTask::getList() const { return m_list; }

void			AbsTask::setLabel(const std::string& p_label) { m_label = p_label; }

void			AbsTask::setDesc(const std::string& p_desc) { m_desc = p_desc; }

void			AbsTask::setParent(AbsTask* p_parent) { m_parent = p_parent; }

void			AbsTask::setList(std::string* p_list) { m_list = p_list; }
