# TCP Client–Server Communication

A full-duplex TCP client-server application written in C using Linux POSIX socket APIs. This project demonstrates practical understanding of network programming, the TCP/IP protocol stack, and system-call level socket operations on Linux.

---

## What It Does

- Establishes a TCP connection between a client and server process
- Supports full-duplex communication — both sending and receiving messages
- Handles the full connection lifecycle: creation, binding, listening, accepting, data transfer, and teardown
- Tests data integrity across multiple message exchanges

---

## Tech Stack

| Category | Details |
|---|---|
| Language | C |
| OS | Linux |
| APIs | `socket()`, `bind()`, `listen()`, `accept()`, `connect()`, `send()`, `recv()` |
| Protocol | TCP/IP |
| Tools | GCC, terminal |

---

## How to Run

**1. Compile**
```bash
gcc server.c -o server
gcc client.c -o client
```

**2. Run the server (in one terminal)**
```bash
./server
```

**3. Run the client (in another terminal)**
```bash
./client
```

---

## Project Structure

```
tcp-client-server/
├── server.c       # Server: binds, listens, accepts connections
├── client.c       # Client: connects and sends messages
└── README.md
```

---

## Key Concepts Demonstrated

- **Socket creation** — `socket()` creates a communication endpoint
- **Binding** — `bind()` assigns an address and port to the socket
- **Connection handling** — `listen()` and `accept()` manage incoming connections
- **Data transfer** — `send()` and `recv()` handle message exchange
- **TCP/IP fundamentals** — reliable, ordered, connection-oriented communication

---

## What I Learned

- How TCP connections are established and torn down
- How Linux exposes networking through POSIX socket APIs at the system-call level
- The difference between TCP and UDP in terms of reliability and connection model
- How client and server processes communicate over a network
