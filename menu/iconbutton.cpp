#include "iconbutton.h"
#include <QBitmap>
#include "utils.h"

IconButton::IconButton(const QPixmap &icon, QWidget *parent)
    : CustomButton(parent), icon_(icon)
{ }

IconButton::IconButton(const QPixmap &icon, const QSize& size, const QSize&icon_size, bool checkable, QWidget *parent)
    : CustomButton(size, checkable, parent), icon_(icon), isize_(icon_size)
{ }

void IconButton::paint(QPainter *painter)
{
    if(isCheckable()){
        auto mask = icon_.createMaskFromColor(Qt::transparent);

        icon_.fill(icon_color_);
        icon_.setMask(mask);
    }
    auto c = rect().center();
    QIcon(icon_).paint(painter, {c.x() - iconSize().width()/2, c.y() - iconSize().height()/2, iconSize().width(), iconSize().height()});
}
