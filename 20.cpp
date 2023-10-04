#include <iostream>
#include <string>

using namespace std;

class AuthenticationResult {
private:
    bool _authenticated;
    string _username;

public:
    AuthenticationResult(bool authenticated, string username = "unauthenticated_user")
        : _authenticated(authenticated), _username(username) {}

    bool authenticated() const {
        return _authenticated;
    }

    string username() const {
        return _username;
    }
};

class IAuthenticationMethod {
public:
    virtual AuthenticationResult authenticate() = 0;
};

class MockAuthentication : public IAuthenticationMethod {
public:
    AuthenticationResult authenticate() override {
        return AuthenticationResult(true, "Default");
    }
};

class UsernamePassword : public IAuthenticationMethod {
public:
    AuthenticationResult authenticate() override {
        string username, password;
        cout << "Username:" << endl;
        cin >> username;
        cout << "Password:" << endl;
        cin >> password;
        if (username == password) {
            return AuthenticationResult(true, username);
        } else {
            return AuthenticationResult(false);
        }
    }
};

class Certificate : public IAuthenticationMethod {
public:
    AuthenticationResult authenticate() override {
        string issuer;
        cout << "Zertifikatsaussteller:" << endl;
        cin >> issuer;
        if (issuer == "hs-esslingen") {
            return AuthenticationResult(true, "certificate.owner");
        } else {
            return AuthenticationResult(false);
        }
    }
};

class Client {
private:
    IAuthenticationMethod* _authentication_method;

public:
    void set_authentication_method(IAuthenticationMethod* authentication_method) {
        _authentication_method = authentication_method;
    }

    void execute() {
        AuthenticationResult result = _authentication_method->authenticate();
        if (result.authenticated()) {
            cout << "Das Programm wird ausgeführt für " << result.username() << "." << endl;
        } else {
            cout << "Das Programm konnte nicht ausgeführt werden." << endl;
        }
    }
};
int main(int argc, char* argv[]) {
    Client client;

    cout << "Authentifizierung über die Authentifizierungsmethode Mock Authentication" << endl;
    IAuthenticationMethod* mock_authentication = new MockAuthentication();
    client.set_authentication_method(mock_authentication);
    client.execute();

    cout << "Authentifizierung über die Authentifizierungsmethode Username Password" << endl;
    IAuthenticationMethod* username_password = new UsernamePassword();
    client.set_authentication_method(username_password);
    client.execute();

    cout << "Authentifizierung über die Authentifizierungsmethode Zertifikat" << endl;
    IAuthenticationMethod* certificate = new Certificate();
    client.set_authentication_method(certificate);
    client.execute();
    return 0;
}

