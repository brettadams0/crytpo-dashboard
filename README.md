# Real-Time Cryptocurrency Dashboard
Welcome to the Real-Time Cryptocurrency Dashboard! This C++ CLI tool allows you to fetch, visualize, and analyze cryptocurrency data using the CoinMarketCap API. It is designed to help you monitor cryptocurrency prices and trends effectively.

## Features
Fetch Real-Time Prices: Get the latest price for any cryptocurrency.
Historical Data: Retrieve and visualize historical price data.
Price Alerts: Set up alerts for significant price changes.
# Prerequisites
To use this application, you need:

libcurl for HTTP requests
nlohmann/json for JSON parsing
matplotlibcpp for plotting (optional, for data visualization)
# Installation
1. Clone the Repository
bash
Copy code
git clone https://github.com/yourusername/crypto-dashboard.git
cd crypto-dashboard
2. Install Dependencies
On Ubuntu/Debian:
bash
Copy code
sudo apt-get update
sudo apt-get install libcurl4-openssl-dev
Install nlohmann/json and matplotlibcpp:
You can download the header files for nlohmann/json from here.

For matplotlibcpp, follow the installation instructions on matplotlibcpp's GitHub page.

3. Build the Project
Create a build directory and compile the project using CMake:

bash
Copy code
mkdir build
cd build
cmake ..
make
Usage
After building the project, you can use the CLI tool to fetch and visualize cryptocurrency data. Here's how you can run it:

bash
Copy code
./CryptoDashboard <crypto_id> <currency> --api_key <your_api_key> [--threshold <percentage>]
Arguments
<crypto_id>: The cryptocurrency symbol (e.g., BTC, ETH).
<currency>: The currency to convert to (e.g., USD).
--api_key <your_api_key>: Your CoinMarketCap API key.
--threshold <percentage>: Alert threshold for price changes (optional, default is 5.0%).
Example
To fetch and display the current price of Bitcoin (BTC) in USD and visualize its historical data with a 5% alert threshold:

bash
Copy code
./CryptoDashboard BTC USD --api_key YOUR_API_KEY --threshold 5.0
Data Visualization
The application uses matplotlibcpp to plot cryptocurrency price trends. Make sure matplotlibcpp is correctly set up to visualize the data.

Testing
You can run tests to ensure everything is working correctly. To test data fetching:

bash
Copy code
cd tests
g++ -o test_data_fetcher test_data_fetcher.cpp -lcurl -ljsoncpp
./test_data_fetcher
License
This project is licensed under the MIT License - see the LICENSE file for details.

Contributing
Contributions are welcome! Please feel free to submit issues or pull requests. For more details on contributing, see CONTRIBUTING.md.

Contact
If you have any questions or need further assistance, you can reach out to your email.

Feel free to modify any sections to better fit your needs or preferences.