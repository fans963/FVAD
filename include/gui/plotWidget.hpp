#include "creeper-qt/widget/widget.hh"
#include <qcolor.h>
#include <qcustomplot.h>
#include <qnamespace.h>

namespace gui {
class PlotWidget : public creeper::Extension<QCustomPlot> {
  Q_OBJECT
public:
  explicit PlotWidget(QWidget *parent = nullptr) : creeper::Extension<QCustomPlot>(parent) {
    setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    xAxis->setTickLabels(true);
    yAxis->setTickLabels(true);
    setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
  }

  void reloadTheme() override {
    setBackground(Qt::blue);
  }
private:
};
} // namespace gui
