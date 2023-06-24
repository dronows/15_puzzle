#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Gameboard.h"

int main(int argc, char* argv[])
{
#if defined(Q_OS_WIN)
 // QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

  QGuiApplication app(argc, argv);
  GameBoard model;
  qmlRegisterType<GameBoard>("Game", 1, 0, "GameBoardModel");
  QQmlApplicationEngine engine;
   engine.addImportPath(":/imports");
  engine.load(QUrl(QStringLiteral("qrc:/imports/PuzzleModule/main.qml")));
  if (engine.rootObjects().isEmpty())
    return -1;

  return app.exec();
}


