#include "blockchain.h"
#include "block.h"
#include "transaction.h"

BlockChain::BlockChain()
{
}

BlockChain::~BlockChain()
{
	for (auto b : m_block_map) {
		delete b.second;
	}
	m_block_map.clear();
}

void BlockChain::addBlock(int id, Block* block)
{
	auto it = m_block_map.find(id);
	if ( it != m_block_map.end() ) {
		return;
	}

	if ( !validateBlock(block) ) {
		return;
	}

	m_block_map.insert( std::make_pair(id, block) );
}

std::list<Block*> BlockChain::getBlockChain() const
{
	std::list<Block*> block_list;

	for (const auto& b : m_block_map) {
		block_list.push_back(b.second);
	}
	return block_list;
}

bool BlockChain::validateBlock(Block* block) const
{
	if (!block) {
		return false;
	}

	if (!block->getTransactionList().size()) {
		return false;
	}

	for (const auto& b : m_block_map) {
		if (b.second->getId() == block->getId()) {
			return false;
		}
	}
	return true;
}

void BlockChain::makeChain()
{
	auto it = m_block_map.begin();

	while ( it != m_block_map.end() ) {
		auto block = it->second;
		auto list = block->getTransactionList();
		auto tr_iter = list.begin();

		while ( tr_iter != list.end() ) {
			auto tr = *tr_iter;

			if (!block->validateTransaction(tr)) {
				++tr_iter;
			}

			if ( tr->getType() == Transaction::EMISSION ) {
				auto name_to = tr->getTo();
				auto client_to = m_clients.find(name_to);

				if ( client_to == m_clients.end() ) {
					m_clients.insert( { name_to, 0 } );
					client_to = m_clients.find(name_to);
				}

				client_to->second += tr->getAmount();

				auto index = std::distance(list.begin(), tr_iter);
				tr_iter = list.erase(tr_iter);
				block->removeTransaction(index);
			} else if ( tr->getType() == Transaction::TRANSFER ) {
				auto name_to = tr->getTo();
				auto client_to = m_clients.find(name_to);

				if ( client_to == m_clients.end() ) {
					m_clients.insert( { name_to, 0 } );
					client_to = m_clients.find(name_to);
				}

				auto name_from = tr->getFrom();
				auto client_from = m_clients.find(name_from);

				if ( client_from == m_clients.end() ) {
					m_clients.insert( { name_from, 0 } );
					client_from = m_clients.find(name_from);
				}

				const auto amount = tr->getAmount();

				if (amount <= client_from->second) {
					client_from->second -= amount;
					client_to->second += amount;
				} // else "BlockChain::Non-sufficient funds!"

				auto index = std::distance(list.begin(), tr_iter);
				tr_iter = list.erase(tr_iter);
				block->removeTransaction(index);
			} else {
				++tr_iter;
			}
		}
		++it;
	}
}

int BlockChain::getBalance(std::string name)
{
	if (name.length() < 2 || name.length() > 100) {
		throw std::runtime_error("BlockChain::invalid name length: '" + \
								 name + "'!");
	}

	makeChain();

	auto client = m_clients.find(name);
	if ( client != m_clients.end() ) {
		return client->second;
	}
	return 0;
}
