#include "creeper-qt/widget/main-window.hh"
#include "gui/plotWidget.hpp"

int main(int argc, char **argv) {
  // qputenv("QT_SCALE_FACTOR", "1");
  auto app = QApplication{argc, argv};

  creeper::Theme::setTheme("common-blue");

  auto window = creeper::MainWindow{};
  auto plot = gui::PlotWidget{&window};
  QIcon icon{":/theme/icon/normal/menu.png"};
  window.setWindowTitle("HelloWorld");
  window.setIconSize({10, 10});
  window.setWindowIcon(icon);
  window.moveCenter();
  plot.resize(800, 600);
  plot.reloadTheme();
  window.show();

  return app.exec();
}