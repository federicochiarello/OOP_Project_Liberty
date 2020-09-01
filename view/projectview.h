#ifndef PROJECTVIEW_H
#define PROJECTVIEW_H

#include <QObject>
#include <QWidget>
#include <QListWidget>
#include <QHBoxLayout>
#include <QShortcut>

#include <vector>
#include <string>

#include "src/globalenums.h"

#include "controller/controller.h"

#include "taskslistwidget.h"

#include <QDebug>

class ProjectView : public QWidget {
	Q_OBJECT

	const unsigned short _id;
	std::vector<TasksListWidget*> _lists;
	const Controller* _controller;

	QVBoxLayout* _mainLayout;
	QHBoxLayout* _centralLayout;

	QLineEdit* _projectName;
	QPushButton* _buttonAddList;

	void connects();
	void setup();

public:
//	explicit ProjectView(QWidget *parent = nullptr);
//	ProjectView(const unsigned short id, const Controller* controller, QWidget* parent);
	ProjectView(const std::pair<unsigned short, QString>& projectInfo, const Controller* controller, QWidget* parent =nullptr);

	unsigned short getId() const;

signals:

//	Creazione liste
	void getLists(const unsigned short);
	void addNewList(const unsigned short);
	void projectNameChanged(const unsigned short, const QString&);
//	void getListName(const unsigned short, const unsigned short);
//	void sendListName(const unsigned short, const QString&);

//	Creazione tasks
	void getTasksIds(const unsigned short, const unsigned short);
	void sendTasksIds(const unsigned short, const std::vector<std::pair<unsigned short, TaskType>>);
	void getTaskName(const unsigned short, const unsigned short, const unsigned short);
	void sendTaskName(const unsigned short, const unsigned short, const QString&);
	void changeProjectName(unsigned short, std::string);

	void forwardTask(unsigned short);
	void backwardTask(unsigned short);

private slots:

	void newList();

public slots:

	void fetchListsIds(const unsigned short projectId, std::vector<unsigned short> listsIds);
	void onAddNewList();
	void fetchListId(const unsigned short projectId, const unsigned short listId);
	void onSetProjectName(const unsigned short projectId, const QString& projectName);

//	void onGetListName(const unsigned short listId);
//	void fetchListName(const unsigned short projectId, const unsigned short listId, const QString& listName);
//	void onGetTasksIds(const unsigned short listId);
//	void onSendTasksIds(const unsigned short projectId, const unsigned short listId, const std::vector<std::pair<unsigned short, TaskType>> tasksIds);
//	void onGetTaskName(const unsigned short listId, const unsigned short taskId);
//	void onSentTaskName(const unsigned short projectId, const unsigned short listId, const unsigned short taskId, const QString& taskName);
};

#endif // PROJECTVIEW_H
