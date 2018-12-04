#include <block.h>
#include <blockchain.h>
#include <transaction.h>

typedef std::tuple<int, int, std::string, std::string, int> Sign_t;
/*!
 * \brief Make signature string
 * \param tuple values
 * \return signature string
 */
inline std::string makeSourceSignature(const Sign_t& v) {
	std::stringstream ss;
	ss << std::get<0>(v) << ":"
	   << std::get<1>(v) << ":"
	   << std::get<2>(v) << ":"
	   << std::get<3>(v) << ":"
	   << std::get<4>(v);
	return ss.str();
}

int main()
{
	std::cout << "Hello Blockchain test!" << std::endl;

	std::string src_sign = makeSourceSignature( std::make_tuple(1,1,"bob","alice",1000) );
	std::string md5_sign = _get_md5_str(src_sign);

	std::cout << md5_sign << std::endl;

	try {
//		void* p_before = sbrk(0);
//		std::cout << "\n\tmemory before: " << (uint64_t)p_before << std::endl;

		// create 100 coins and transfer them to Bob
		Transaction* trx = new Transaction();
		trx->setId(1);
		trx->setType(Transaction::EMISSION);
		trx->setTo("bob");
		trx->setAmount(100);
		trx->setSignature(md5_sign);

		Block* block = new Block();
		block->setId(1);
		block->addTransaction(trx);

		BlockChain* blockChain = new BlockChain();
		blockChain->addBlock(0, block);

		// bob transfers 50 coins to alice
		trx = new Transaction();
		trx->setId(2);
		trx->setType(Transaction::TRANSFER);
		trx->setFrom("bob");
		trx->setTo("alice");
		trx->setAmount(50);
		trx->setSignature(md5_sign);

		block = new Block();
		block->setId(2);
		block->addTransaction(trx);

		blockChain->addBlock(1, block);

		// should return 50
		std::cout << "Alice balance: "
				  << blockChain->getBalance("alice") << std::endl;

		// should return 50
		std::cout << "Bob balance: "
				  << blockChain->getBalance("bob")<< std::endl;

		delete blockChain;

//		void* p_after = sbrk(0);
//		std::cout << "\n\tmemory after: " << (uint64_t)p_after << std::endl;
	} catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}
