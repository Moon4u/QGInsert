
#include <QDebug>
#include <qt_windows.h>
#include <QApplication>
#include <QObject>

#include "mainwindow.h"

const int	MOD_NOREPEAT	= 0x4000;

void	onHotkeyMessageArrived( HWND activeWindow );

void	nativeEvent()
{
	RegisterHotKey( NULL, 1, MOD_ALT | MOD_NOREPEAT, 0x47 );

	while( true )
	{
		MSG	msg;
		while( GetMessage( &msg, NULL, 0, 0 ) )
		{
			if( msg.message == WM_HOTKEY )
				onHotkeyMessageArrived( GetForegroundWindow() );
		}
	}

	UnregisterHotKey( NULL, 1 );
}


void	onHotkeyMessageArrived( HWND activeWindow )
{
	int argc = 0;
	QApplication	a( argc, nullptr );
	MainWindow		w( activeWindow );
	w.show();
	w.activateWindow();
	w.raise();
	a.exec();
}



int	main( int, char** )
{
	nativeEvent();
	return	0;
}
