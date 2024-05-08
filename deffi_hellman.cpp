/* This program calculates the Key for two persons
using the Diffie-Hellman Key exchange algorithm using C++ */
#include <cmath>
#include <iostream>

using namespace std;

// Power function to return value of a ^ b mod P
long long int power(long long int a, long long int b, long long int P)
{
    if (b == 1)
        return a;

    else
        return (((long long int)pow(a, b)) % P);
}

// Driver program
int main()
{
    long long int P, G, x, a, y, b, ka, kb;

    // Both the persons will be agreed upon the
    // public keys G and P
    P = 23; // A prime number P is taken
    cout << "The value of P : " << P << endl;

    G = 9; // A primitive root for P, G is taken
    cout << "The value of G : " << G << endl;

    // Alice will choose the private key a
    a = 5; // a is the chosen private key
    cout << "The private key a for Alice : " << a << endl;

    x = power(G, a, P); // gets the generated key

    // Bob will choose the private key b
    b = 10; // b is the chosen private key
    cout << "The private key b for Bob : " << b << endl;

    y = power(G, b, P); // gets the generated key

    // Generating the secret key after the exchange
    // of keys
    ka = power(y, a, P); // Secret key for Alice
    kb = power(x, b, P); // Secret key for Bob
    cout << "Secret key for the Alice is : " << ka << endl;

    cout << "Secret key for the Bob is : " << kb << endl;

    return 0;
}

/*
<!DOCTYPE html>
<html>
<head>
    <title>Diffie-Hellman Key Exchange</title>
</head>
<body>
    <h1>Diffie-Hellman Key Exchange</h1>
    <p>Click the button to perform the key exchange:</p>
    <button onclick="performKeyExchange()">Perform Key Exchange</button>
    <h2>Results</h2>
    <div id="results"></div>

    <script>
        const prime = 23;
        const base = 5;
        function binexpitr(a, b) { 
	        let ans = 1;
	        while (b) {
		        if (b & 1) ans = (ans * a) % prime;
		        a = (a * a) % prime;
		        b >>= 1;
            }
            return ans;
	    }
        function performKeyExchange() {
            // Constants for the prime number and the base
            

            // Alice's private key
            const alicePrivateKey = 16; // Assume Alice chooses this randomly

            // Bob's private key
            const bobPrivateKey = Math.floor(Math.random() * 10) + 1;

            // Calculate Alice's public key
            const alicePublicKey = binexpitr(base, alicePrivateKey) % prime;

            // Calculate Bob's public key
            const bobPublicKey = binexpitr(base, bobPrivateKey) % prime;

            // Exchange public keys
            const sharedKeyAlice = binexpitr(bobPublicKey, alicePrivateKey) % prime;
            const sharedKeyBob = binexpitr(alicePublicKey, bobPrivateKey) % prime;

            // Display the results
            const resultsDiv = document.getElementById("results");
            resultsDiv.innerHTML = `
                <p>Alice's private key: ${alicePrivateKey}</p>
                <p>Alice's public key: ${alicePublicKey}</p>
                <p>Bob's private key: ${bobPrivateKey}</p>
                <p>Bob's public key: ${bobPublicKey}</p>
                <p>Shared key calculated by Alice: ${sharedKeyAlice}</p>
                <p>Shared key calculated by Bob: ${sharedKeyBob}</p>
                <p>Keys match: ${sharedKeyAlice === sharedKeyBob}</p>
            `;
        }
    </script>
</body>
</html>
*/
