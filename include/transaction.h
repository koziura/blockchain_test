#ifndef TRANSACTION_H
#define TRANSACTION_H
/*!
 * \brief The Transaction class
 */
class Transaction
{
public:
	/*!
	 * \brief The Type enum of Transaction
	 */
	enum Type { EMISSION, TRANSFER };
	/*!
	 * \brief class constructor
	 */
	Transaction();
	/*!
	 * \brief Getting Id
	 * \return id value
	 */
	int getId() const;
	/*!
	 * \brief Setting Id
	 * \param id value
	 */
	void setId(int id);
	/*!
	 * \brief Getting Type
	 * \return type enum of Transaction
	 */
	int getType() const;
	/*!
	 * \brief Setting Type
	 * \param type enum of Transaction
	 */
	void setType(int type);
	/*!
	 * \brief Geting username from which the translation
	 * \return username
	 */
	std::string getFrom() const;
	/*!
	 * \brief Setting username from which the translation
	 * \param username
	 */
	void setFrom(std::string name);
	/*!
	 * \brief Getting username for which the translation
	 * \return username
	 */
	std::string getTo() const;
	/*!
	 * \brief Setting username for which the translation
	 * \param username
	 */
	void setTo(std::string name);
	/*!
	 * \brief Getting amount
	 * \return value
	 */
	int getAmount() const;
	/*!
	 * \brief Setting amount
	 * \param value
	 */
	void setAmount(int value);
	/*!
	 * \brief Getting signature
	 * \return signature value
	 */
	std::string getSignature() const;
	/*!
	 * \brief Setting signature
	 * \param signature value
	 */
	void setSignature(std::string sign);

private:
	int m_id;					///< Transaction id
	int m_type;					///< Type enum of Transaction
	int m_amount;				///< Transaction amount
	std::string m_from;			///< Transaction from username
	std::string m_to;			///< Transaction to username
	std::string m_signature;	///< Signature of transaction
};

#endif // TRANSACTION_H
