#include "block.h"
#include "transaction.h"

Block::Block():
	m_id(-1)
{
}

Block::~Block()
{
	for (auto tr : m_transact_list) {
		if (tr) {
			delete tr;
		}
	}
	m_transact_list.clear();
}

int Block::getId() const
{
	return m_id;
}

void Block::setId(int id)
{
	if (id < 0) {
		throw std::runtime_error("Block::invalid id!");
	}
	m_id = id;
}

void Block::addTransaction(Transaction* transact)
{
	if (!transact) {
		throw std::runtime_error("Block::null transact object!");
	}
	m_transact_list.push_back(transact);
}

bool Block::validateTransaction(Transaction* transact) const
{
	std::stringstream ss;
	ss << transact->getId() << ":"
	   << transact->getType() << ":"
	   << transact->getFrom() << ":"
	   << transact->getTo() << ":"
	   << transact->getAmount();

	std::string md5_sign = _get_md5_str(ss.str());

	try {
		transact->setSignature(md5_sign);
	} catch (/*const std::exception& ex*/ ... ) {
		//std::cout << ex.what() << std::endl;
		return false;
	}
	return true;
}

std::list<Transaction*> Block::getTransactionList() const
{
	return m_transact_list;
}

void Block::removeTransaction(int index)
{
	auto it = std::next(m_transact_list.begin(), index);

	if (it == m_transact_list.end()) {
		return;
	}

	Transaction* transact(*it);
	if (transact) {
		delete transact;
	}
	m_transact_list.erase(it);
}
