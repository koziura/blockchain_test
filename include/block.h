#ifndef BLOCK_H
#define BLOCK_H
/*!
 * ref`s pointer Transaction class
 */
class Transaction;
/*!
 * \brief The Block class
 */
class Block
{
public:
	/*!
	 * \brief class constructor
	 */
	Block();
	~Block();
	/*!
	 * \brief Setting Id
	 * \param id value
	 */
	int getId() const;
	/*!
	 * \brief Setting id for this block
	 * \param id value
	 */
	void setId(int id);
	/*!
	 * \brief Adding transaction for this block
	 * \param transact pointer of Transaction class
	 */
	void addTransaction(Transaction* transact);
	/*!
	 * \brief Validate passed transaction
	 * \param transact pointer of Transaction class
	 * \return true - if the passed transaction is valid
	 */
	bool validateTransaction(Transaction* transact) const;
	/*!
	 * \brief Getting transaction list for this block
	 * \return list transaction
	 */
	std::list<Transaction*> getTransactionList() const;
	/*!
	 * \brief Removing transaction from transaction list
	 * \param index position of list
	 */
	void removeTransaction(int index);

private:
	int m_id;	///< Block id
	std::list<Transaction*> m_transact_list;	///< Transaction list

};

#endif // BLOCK_H
