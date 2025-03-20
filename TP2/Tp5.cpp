#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Function for Standard ACL (source IP filtering)
void aclRule(string action, string srcIP, string srcMask) {
    cout << action << " " << srcIP << " " << srcMask << endl;
}

// Function for Extended ACL (source IP, destination IP, and protocol)
void aclRule(string action, string srcIP, string srcMask, string dstIP, string dstMask, string protocol) {
    cout << action << " " << srcIP << " " << srcMask << " " << dstIP << " " << dstMask << " " << protocol << endl;
}

// Function to check if an IP matches a rule (considering wildcard mask)
bool matchesRule(string ip, string ruleIp, string wildcard) {
    istringstream ipStream(ip), ruleIpStream(ruleIp), wildcardStream(wildcard);
    int ipPart, ruleIpPart, wildcardPart;
    
    for (int i = 0; i < 4; i++) {
        char dot;
        ipStream >> ipPart;
        ruleIpStream >> ruleIpPart;
        wildcardStream >> wildcardPart;
        
        if (ipStream.peek() == '.') ipStream >> dot;
        if (ruleIpStream.peek() == '.') ruleIpStream >> dot;
        if (wildcardStream.peek() == '.') wildcardStream >> dot;

        if ((ipPart & ~wildcardPart) != (ruleIpPart & ~wildcardPart)) {
            return false;
        }
    }
    return true;
}

int main() {
    int numRules;
    cout << "Enter number of ACL rules: ";
    cin >> numRules;
    cin.ignore();

    vector<string> actions, srcIPs, srcMasks, dstIPs, dstMasks, protocols;

    for (int i = 0; i < numRules; i++) {
        string action, srcIP, srcMask, dstIP = "any", dstMask = "any", protocol = "any";
        cout << "Enter ACL Rule " << i + 1 << ": ";
        cin >> action >> srcIP >> srcMask;
        
        if (cin.peek() != '\n') {
            cin >> dstIP >> dstMask >> protocol;
        }
        cin.ignore();

        actions.push_back(action);
        srcIPs.push_back(srcIP);
        srcMasks.push_back(srcMask);
        dstIPs.push_back(dstIP);
        dstMasks.push_back(dstMask);
        protocols.push_back(protocol);
    }

    string testSrcIP, testDstIP, testProtocol;
    cout << "Enter source IP to test: ";
    cin >> testSrcIP;
    cout << "Enter Destination IP to test: ";
    cin >> testDstIP;
    cout << "Enter Protocol (tcp/udp/any): ";
    cin >> testProtocol;

    for (size_t i = 0; i < actions.size(); i++) {
        if (matchesRule(testSrcIP, srcIPs[i], srcMasks[i]) &&
            (dstIPs[i] == "any" || matchesRule(testDstIP, dstIPs[i], dstMasks[i])) &&
            (protocols[i] == "any" || protocols[i] == testProtocol)) {
            cout << (actions[i] == "permit" ? "ACCESS GRANTED" : "ACCESS DENIED") << endl;
            return 0;
        }
    }
    
    cout << "ACCESS DENIED" << endl;
    return 0;
}
