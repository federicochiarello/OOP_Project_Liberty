#include "taskslist.h"

static inline QString libertyMimeType() {return QStringLiteral("application/x-Liberty");}

TasksList::TasksList(const unsigned short id, const unsigned short projectId, const Controller* controller, QWidget *parent) :
	QScrollArea(parent),
	_id(id),
	_projectId(projectId),
	_controller(controller),
	_layout(new QVBoxLayout()),
	_widget(new QWidget(this)) {

//	setDragEnabled(true);
	setAcceptDrops(true);
	setWidgetResizable(true);

	_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	_widget->setLayout(_layout);
	_widget->autoFillBackground();
	setWidget(_widget);

//	addWidget(new TaskPreview(tr("Insert task name"), 0, this));

}

void TasksList::addWidget(QLineEdit* wdgt) {
	dynamic_cast<QVBoxLayout*>(widget()->layout())->addWidget(wdgt);
}

void TasksList::dragMoveEvent(QDragMoveEvent* event) { // spostamento task all'interno della lista

}

void TasksList::dragEnterEvent(QDragEnterEvent* event) { // spostamento di un task da un'altra lista all'interno di quella corrente
	event->accept();
}

void TasksList::dragLeaveEvent(QDragLeaveEvent* event) { // spostamento di un task al di fuori della lista corrente

}

void TasksList::dropEvent(QDropEvent* event) { // aggiunta di un task alla lista da un'altra lista
	//auto data = event->mimeData();
}

void TasksList::mousePressEvent(QMouseEvent *event) {
//	TaskWidget* child = dynamic_cast<TaskWidget*>(childAt(event->pos()));
//	// forse uso di eccezioni
//	if (!child) return;

//	QPoint hotspot = event->pos() -  child->pos();

//	QByteArray itemData;
//	QDataStream dataStream(&itemData, QIODevice::WriteOnly);
//	dataStream << child->getData() << QPoint(hotspot);

//	QMimeData* mimeData = new QMimeData;
//	mimeData->setData(libertyMimeType(), itemData);
//	mimeData->setText(child->getData());
}

void TasksList::addTask() {
//	// add request and get id
//	unsigned short id = 0;
//	TaskPreview* newTask = new TaskPreview(tr(""), id, this);
//	addWidget(newTask);
//	newTask->setFocus();
	//	//dynamic_cast<TaskPreview*>(widget()->layout()->itemAt(widget()->layout()->count()))->setFocus();
}

void TasksList::addTask(const std::pair<unsigned short, TaskType>& taskId) {
	TaskPreview* task;
	switch (taskId.second) {
		case TASK:
			task = new TaskPreview(taskId.first, _id, _projectId, _controller, this);
			break;
		case TASK_CONTAINER:
			task = new TaskContainerPreview(taskId.first, _id, _projectId, _controller, this);
			break;
		case TASK_PRIORITY:
			task = new TaskPriorityPreview(taskId.first, _id, _projectId, _controller, this);
			break;
		case TASK_PRIORITY_CONTAINER:
			task = new TaskPriorityContainerPreview(taskId.first, _id, _projectId, _controller, this);
			break;
	}
	addWidget(task);
}

DragDrop::DragDrop(QWidget* parent) : QWidget(parent) {
	setLayout(new QVBoxLayout());
	layout()->addWidget(new QLineEdit(tr("1"), this));
	layout()->addWidget(new QLineEdit(tr("2"), this));
}

void DragDrop::dragMoveEvent(QDragMoveEvent *event) {

	if (event->mimeData()->hasFormat(libertyMimeType())) {
		if (children().contains(event->source())) {
			event->setDropAction(Qt::MoveAction);
			event->accept();
		}
		else event->acceptProposedAction();
	}
	else event->ignore();

}

void DragDrop::dragEnterEvent(QDragEnterEvent *event) {

	if (event->mimeData()->hasFormat(libertyMimeType())) {
		   if (children().contains(event->source())) {
			   event->setDropAction(Qt::MoveAction);
			   event->accept();
		   }
		   else event->acceptProposedAction();
	}
	else event->ignore();
}

void DragDrop::dragLeaveEvent(QDragLeaveEvent *event) {

}

void DragDrop::dropEvent(QDropEvent *event) {

}

void DragDrop::mousePressEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {

	}
}


