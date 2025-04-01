# Credit Card Fraud Detection System

This is a simple **Credit Card Fraud Detection System** that processes financial transactions to detect possible fraud.

The program takes user input for a transaction (card number, amount) and processes it, masking the card number and applying basic fraud detection. It also encrypts sensitive information using **AES encryption** and ensures **rate-limited** requests. 

## **Features**
- **Card Number Masking**: Displays masked card number for privacy (`XXXX` format).
- **Automatic Country Detection**: Automatically detects the country from which the transaction was made. 
- **Automatic Date and Time Detection**: Automatically detects the date and time when the transaction occurred. 
- **Fraud Detection**: Identifies if a transaction is legitimate or suspicious (by country and amount).
- **AES Encryption**: Encrypts sensitive data during processing for security.
- **Transaction Logging**: Logs the transaction result, including encrypted data for future analysis.
- **Rate Limiting**: Prevents multiple transactions in a short time frame.

## **Requirements**
To compile and run the project, ensure the following dependencies are installed:
- **C++ Compiler**: g++ (or compatible compiler).
- **OpenSSL**: For encryption functions (`libssl-dev`).

## **Installation for Dependencies:**
```bash
sudo apt-get update
sudo apt-get install g++ libssl-dev
```

## **Setup Instructions**
1. Clone the repository to your local machine:
```bash
git clone https://github.com/yovanabozhilov/Credit-Card-Fraud-Detector.git
cd Credit-Card-Fraud-Detector
```
2. Build the project by running the following comand:
```bash
make
```
3. Run the program:
```bash
./executable
```
4. After building the project, you can clean up object files and the executable by running:
```bash
make clean
```

## **Input Format**
The program expects a valid credit card number containing 16 digits, as well as a transaction amount. By default, the maximum non-suspicious transaction amount is set to **18,000 BGN**. Any amount exceeding this value is marked as suspicious. Additionally, transactions made from any country other than the one where the credit card user is registered are also flagged as potential fraud attempts.

Example input: 
```yaml 
Enter Card Number: 6789543267530975
Enter Transaction Amount: 100
```

## **Output Format**
The output provides a masked card number, the date and time of the transaction, the country, and the transaction amount. It then processes the transaction and determines whether it is fraudulent based on two key factors: the country and the transaction amount. Finally, the transaction data is logged into **transaction_log.txt**.

Example output: 
```yaml 
========================================
           TRANSACTION DETAILS          
========================================
🔒 Card: 6789-XXXX-XXXX-0975
📅 Date of Transaction:  2025-03-21 04:55:29
🌍 Transaction made from: BG
💰 Transaction amount:    100.00

🚀 Processing Transaction...
⚠️  Fraud Detection Result: Legitimate
========================================
```
