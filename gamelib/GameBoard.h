// Cmake_15puzzle.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include <iostream>
#include <QObject> 
#include <QAbstractListModel>

#include <algorithm>
#include <random>



class GameBoard : public QAbstractListModel
{
  Q_OBJECT
    Q_PROPERTY(int dimension READ dimension CONSTANT)
    Q_PROPERTY(int hiddenElementValue READ boardsize CONSTANT)

public:
  static constexpr size_t defaultPuzzleDimension{ 4 };
  GameBoard(const size_t boardDimension = defaultPuzzleDimension,
    QObject* parent = nullptr);

  using Position = std::pair<size_t, size_t>;

  struct Tile {
    size_t value{};
    Tile& operator= (const size_t newValue) {
      value = newValue;
      return *this;
    }
    bool operator==(const size_t other) {
      return other == value;
    }
  };

  Q_INVOKABLE bool move(int index);
  size_t dimension()const;
  size_t boardsize() const;
  int rowCount(const QModelIndex& parent = QModelIndex{}) const override;
  QVariant data(const QModelIndex& index, int role = Qt::DisplayRole)const override;
  Position getRowCol(size_t index)const;

private:
  void shuffle();
  bool isPositionValid(const size_t position) const;
  bool isBoardValid() const;
  std::vector<Tile> m_rawBoard;
  const size_t m_dimension;
  const size_t m_boardSize;
};

//================================================================================================



