#include <iostream>

// function to handle integer IP address
void routePacket(int ipAddress) {
    std::cout << "Routing packet to IP (int): " << ipAddress << std::endl;
    // Assuming that we can seperate networks with integer idAdresses 
    if (ipAddress > 1000 && ipAddress < 2000) {
        std::cout << "  -> Forwarding to network A" << std::endl;
    } else if (ipAddress >= 2000 && ipAddress < 3000) {
        std::cout << "  -> Forwarding to network B" << std::endl;
    } else {
        std::cout << "  -> Forwarding to default gateway" << std::endl;
    }
}
// function to handle string IP address
void routePacket(const std::string& ipAddress) {
    std::cout << "Routing packet to IP (string) : " << std::endl ;
    // Simulating routing logic
    if(ipAddress.substr(0,3) == "192"){
        std::cout << "  -> Forwarding to the local network " << std::endl;
    }else if (ipAddress.substr(0,3) == "10."){
        std::cout << "  -> Forwarding to private network " << std::endl;
    }else {
        std::cout << "  -> Forwarding to the internet " << std::endl;
    }
    
}

// function to handle source and destination IP addresses
void routePacket(const std::string& sourceIp, const std::string& destinationIp) {
    std::cout << "Routing packet from " << sourceIp << " to " << destinationIp << std::endl;
    // Simulate routing logic based on source and destination IPs
    if (sourceIp.substr(0, 3) == "192" && destinationIp.substr(0, 3) == "192") {
        std::cout << "  -> Routing within local network" << std::endl;
    } else if (destinationIp.substr(0, 3) == "10.") {
        std::cout << "  -> Routing to private network" << std::endl;
    } else {
        std::cout << "  -> Routing to external network" << std::endl;
    }
}

// function handle source IP, destination IP, and protocol
void routePacket(const std::string& sourceIp, const std::string& destinationIp, const std::string& protocol) {
    std::cout << "Routing packet from " << sourceIp << " to " << destinationIp << " (Protocol: " << protocol << ")" << std::endl;
    // Simulate routing logic based on source, destination, and protocol
    if (protocol == "TCP") {
        std::cout << "  -> Using TCP routing rules" << std::endl;
        if (destinationIp.substr(0, 3) == "10.")
        {
            std::cout << "   -> Forwarding to private network" << std::endl;
        }
        else
        {
            std::cout << "   -> Forwarding to external network" << std::endl;
        }
    } else if (protocol == "UDP") {
        std::cout << "  -> Using UDP routing rules" << std::endl;
        if (destinationIp.substr(0, 3) == "192")
        {
            std::cout << "   -> Forwarding to local network" << std::endl;
        }
        else
        {
            std::cout << "   -> Forwarding to external network" << std::endl;
        }
    } else {
        std::cout << "  -> Unknown protocol, using default routing" << std::endl;
        std::cout << "   -> Forwarding to default gateway" << std::endl;
    }
}



int main() {
     // Test cases
    std::cout << "--- Test Case 1: Integer IP ---" << std::endl;
    routePacket(1500);
    std::cout << std::endl;

    std::cout << "--- Test Case 2: String IP ---" << std::endl;
    routePacket("192.168.1.1");
    std::cout << std::endl;

    std::cout << "--- Test Case 3: String IP ---" << std::endl;
    routePacket("10.0.0.1");
    std::cout << std::endl;

    std::cout << "--- Test Case 4: Source and Destination IPs ---" << std::endl;
    routePacket("192.168.1.10", "192.168.1.20");
    std::cout << std::endl;

    std::cout << "--- Test Case 5: Source and Destination IPs ---" << std::endl;
    routePacket("192.168.1.10", "8.8.8.8");
    std::cout << std::endl;

    std::cout << "--- Test Case 6: Source, Destination, and Protocol ---" << std::endl;
    routePacket("192.168.1.10", "10.0.0.5", "TCP");
    std::cout << std::endl;

    std::cout << "--- Test Case 7: Source, Destination, and Protocol ---" << std::endl;
    routePacket("192.168.1.10", "8.8.8.8", "UDP");
    std::cout << std::endl;
    
    std::cout << "--- Test Case 8: Source, Destination, and Protocol ---" << std::endl;
    routePacket("192.168.1.10", "8.8.8.8", "ICMP");
    std::cout << std::endl;


    return 0;
}
