
#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

#include <QWidget>
class	SearchBox;
class	HS_SendKeys;

class MainWindow : public QWidget
{
	Q_OBJECT

public:
	explicit	MainWindow( HWND activeWindow );
	virtual		~MainWindow();

public slots:
	void	onNewText( const QString& sendString );

protected:
	void	keyPressEvent( QKeyEvent* event );
	void	keyReleaseEvent( QKeyEvent* event );


private:
	HWND			m_activeWindow;
	QLayout*		m_layout;
	SearchBox*		m_searchField;
	QFont			m_font;
	HS_SendKeys*	m_sendKeys;
};

#endif // __MAIN_WINDOW_H__
