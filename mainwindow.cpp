
#include <QKeyEvent>
#include <QVBoxLayout>
#include <QDebug>

#include <qt_windows.h>

#include "gsuggestcompletion.h"
#include "searchbox.h"
#include "mainwindow.h"
#include "au3/sendkeys.h"

MainWindow::MainWindow( HWND activeWindow ) :
	QWidget( NULL )
{
	setWindowFlags( Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint );
	m_activeWindow	= activeWindow;

	m_sendKeys		= new HS_SendKeys();

	m_font			= QFont( "Tahoma", 20, 400 );
	m_layout		= new QVBoxLayout( this );
	m_searchField	= new SearchBox( this );

	qDebug() << "Active Window Is " << activeWindow;
	qDebug() << "This Window Is " << winId();
	m_searchField->setFont( m_font );
	m_layout->addWidget( m_searchField );
	connect( m_searchField->getCompleter(), SIGNAL( sendText(const QString& ) ),
			 this, SLOT( onNewText( QString ) ) );
}

MainWindow::~MainWindow()
{
	delete	m_searchField;
	delete	m_layout;
}


void	MainWindow::keyPressEvent(QKeyEvent *event)
{
	switch( event->key() )
	{
		case	Qt::Key_Return:
		case	Qt::Key_Enter:
			//internalPostMessage();

		case	Qt::Key_Escape:
			close();

		default:
			return;
	}
}

void	MainWindow::keyReleaseEvent(QKeyEvent *event)
{
	Q_UNUSED( event );
}

void	MainWindow::onNewText( const QString& sendString )
{
	SetForegroundWindow( m_activeWindow );
	m_sendKeys->Send( sendString.toUtf8().data(), m_activeWindow );
	close();
}
