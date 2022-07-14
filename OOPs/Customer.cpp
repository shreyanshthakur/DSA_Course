class Customer{
    private:
        string secret_text;
    public:
        string name;

        string get_secret_text () {
            cout << "Please enter your password: ";
            //lock
            string s;
            cin >> s;
            if (s == "12345") {
                cout << "Secret text is: " << endl;
                return secret_text;
            }
            else {
                return "Wrong Password";
            }
        }
        void set_secret_text () {
            string s;
            cout << "Enter the secret text: ";
            cin >> s;
            secret_text = s;
            cout << "\nSuccess"<< endl;;
        }
};