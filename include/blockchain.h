#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
/*!
 * ref`s pinter Block class
 */
class Block;
/*!
 * \brief The BlockChain class
 */
class BlockChain
{
public:
	/*!
	 * \brief class constructor
	 */
	BlockChain();
	~BlockChain();
	/*!
	 * \brief Adding block of transactions
	 * \param id value
	 * \param Block pointer of Block class
	 */
	void addBlock(int id, Block* block);
	/*!
	 * \brief Getting block list
	 * \return Block list
	 */
	std::list<Block*> getBlockChain() const;
	/*!
	 * \brief Validate passed block
	 * \param block pointer
	 * \return true – if the passed block is valid
	 */
	bool validateBlock(Block* block) const;
	/*!
	 * \brief Getting balance by username
	 * \param Username string
	 * \return Balance value
	 */
	int getBalance(std::string name);
	/*!
	 * \brief Running blockchain operations for added blocks
	 */
	void makeChain();

private:
	std::unordered_map <std::string, int> m_clients; ///< client list for this blockchain
	std::map<int, Block*> m_block_map; ///< block list for this blockchain
};

#endif // BLOCKCHAIN_H
