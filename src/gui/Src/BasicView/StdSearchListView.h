#pragma once

#include "SearchListView.h"
#include "StdTableSearchList.h"

class StdSearchListView : public SearchListView
{
    Q_OBJECT
public:
    StdSearchListView(QWidget* parent, bool enableRegex, bool enableLock);
    StdSearchListView(QWidget* parent, bool enableRegex, bool enableLock, StdTableSearchList* tableSearchList);
    ~StdSearchListView() override;

    void setInternalTitle(const QString & title);
    int getCharWidth();
    void addColumnAt(int width, QString title, bool isClickable, QString copyTitle = "", StdTable::SortBy::t sortFn = StdTable::SortBy::AsText);
    void setDrawDebugOnly(bool value);
    void enableMultiSelection(bool enabled);
    void setAddressColumn(int col, bool cipBase = false);
    void loadColumnFromConfig(const QString & viewName);

public slots:
    virtual void setRowCount(dsint count);
    void setCellContent(int r, int c, QString s);
    void reloadData();
    void setSearchStartCol(duint col);

private:
    StdTableSearchList* mSearchListData;

protected:
    friend class SymbolView;
    friend class Bridge;
    friend class HandlesView;

    StdTable* stdList();
    StdTable* stdSearchList();
};
