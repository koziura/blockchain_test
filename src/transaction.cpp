#include "transaction.h"

Transaction::Transaction():
	m_id(-1), m_type(-1), m_amount(0)
{
}

int Transaction::getId() const
{
	return m_id;
}

void Transaction::setId(int id)
{
	if (id < 0) {
		throw std::runtime_error("Transaction::invalid id!");
	}
	m_id = id;
}

int Transaction::getType() const
{
	return m_type;
}

void Transaction::setType(int type)
{
	if (type != EMISSION && type != TRANSFER) {
		throw std::runtime_error("Transaction::unknown type!");
	} else if (type == EMISSION) {
		m_from.clear();
	}
	m_type = type;
}

std::string Transaction::getFrom() const
{
	return m_from;
}

void Transaction::setFrom(std::string name)
{
	if (m_type == EMISSION) {
		m_from.clear();
		return;
	} else if (name.length() < 2 || name.length() > 10) {
		throw std::runtime_error("Transaction::invalid name: " + name + "!");
	}
	m_from = name;
}

std::string Transaction::getTo() const
{
	return m_to;
}

void Transaction::setTo(std::string name)
{
	if (name == m_from) {
		throw std::runtime_error("Transaction::identical names!");
	}
	m_to = name;
}

int Transaction::getAmount() const
{
	return m_amount;
}

void Transaction::setAmount(int value)
{
	if (value < 1) {
		throw std::runtime_error("Transaction::identical names!");
	}
	m_amount = value;
}

std::string Transaction::getSignature() const
{
	return m_signature;
}

void Transaction::setSignature(std::string sign)
{
	if (sign.length() != 32) {
		throw std::runtime_error("Transaction::invalid signature!");
	}
	m_signature = sign;
}
