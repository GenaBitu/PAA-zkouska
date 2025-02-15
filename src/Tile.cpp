#include "main.hpp"

Direction Tile::begin() const
{
	return Direction{this, 0};
}

Direction Tile::end() const
{
	return Direction{this, 26};
}

const bool Tile::operator!=(const Tile& other) const
{
	return column != other.column || tile != other.tile;
}

Tile* Tile::operator++()
{
	++tile;
	return this;
}

Tile& Tile::operator*()
{
	return *this;
}

const Column* Tile::getColumn() const
{
	return column;
}

const vec Tile::getCenter() const
{
	const Lattice* lattice{column->getLayer()->getLattice()};
	return {lattice->getXMin() + (tile + 0.5f) * lattice->getTileSize(), lattice->getYMin() + (column->getColumn() + 0.5f) * lattice->getTileSize(), lattice->getZMin() + (column->getLayer()->getLayer() + 0.5f) * lattice->getTileSize()};
}

Tile::Tile(const Column* column, const int tile) : column{column}, tile{tile}
{}
