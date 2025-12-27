# 🎥 Live Stream API & WebSocket Documentation

## 📋 Table of Contents

1. [REST API Endpoints](#rest-api-endpoints)
2. [WebSocket Events](#websocket-events)
3. [Complete Integration Guide](#complete-integration-guide)
4. [Example Code](#example-code)

---

## 🔗 REST API Endpoints

### Base URL

```
http://localhost:8000/api/v1
```

---

### 1. **Create & Start Live Stream** (Host)

**Endpoint:** `POST /livestream/`

**Headers:**

```json
{
  "Authorization": "Bearer YOUR_ACCESS_TOKEN",
  "Content-Type": "application/json"
}
```

**Request Body:**

```json
{
  "product_id": 6,
  "title": "My Live Stream",
  "description": "Optional description"
}
```

**Response (200):**

```json
{
    "success": true,
    "message": "Stream created and started",
    "data": {
        "stream": {
            "id": 11,
            "seller_name": "nebadcen5372",
            "product_name": "Ikea Hemnes Bed Frame",
            "title": "HP Spectre x360",
            "description": "Watch live unboxing!",
            "status": "live",
            "room_name": "room_AmLlzyGgC9gBXy_RBNjZJg",
            "scheduled_at": "2025-12-24T09:12:50.562553Z",
            "started_at": "2025-12-24T09:12:50.568982Z",
            "ended_at": null,
            "viewer_count": 0,
            "peak_viewers": 0,
            "created_at": "2025-12-24T09:12:50.562971Z",
            "updated_at": "2025-12-24T09:12:50.569058Z",
            "product": 6,
            "seller": 9
        },
        "livekit": {
            "url": "wss://imp-0svjfn9q.livekit.cloud",
            "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6Ikp..",
            "room_name": "room_AmLlzyGgC9gBXy_RBNjZJg",
            "identity": "host_nebadcen5372_1766567570"
        }
    }
}
```

**Purpose:**

- Host একবার call করবে stream create করতে
- সাথে সাথে live start হবে
- LiveKit token পাবে streaming এর জন্য

---

### 2. **Join Live Stream** (Viewer)

**Endpoint:** `GET /livestream/{stream_id}/join/`

**Headers:**

```json
{
  "Authorization": "Bearer YOUR_ACCESS_TOKEN" // Optional for guests
}
```

**Response (200):**

```json
{
    "success": true,
    "message": "Successfully joined stream",
    "data": {
        "livekit_url": "wss://imp-0svjfn9q.livekit.cloud",
        "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6I..",
        "room_name": "room_3aAiu_Z2fwoDyuxa5IJKnA",
        "stream": {
            "id": 10,
            "seller_name": "nebadcen5372",
            "product_name": "Ikea Hemnes Bed Frame",
            "title": "HP Spectre x360",
            "description": "Watch live unboxing!",
            "status": "live",
            "room_name": "room_3aAiu_Z2fwoDyuxa5IJKnA",
            "scheduled_at": "2025-12-24T09:05:19.331578Z",
            "started_at": "2025-12-24T09:05:19.334471Z",
            "ended_at": null,
            "viewer_count": 0,
            "peak_viewers": 0,
            "created_at": "2025-12-24T09:05:19.331831Z",
            "updated_at": "2025-12-24T09:05:19.334555Z",
            "product": 6,
            "seller": 9
        }
    }
}
```

**Error Response (400):**

```json
{
  "error": "Stream is not live",
  "status": "ended"
}
```

**Purpose:**

- Viewer/Customer এই API call করবে live দেখার জন্য
- LiveKit viewer token পাবে

---

### 3. **End Live Stream** (Host)

**Endpoint:** `POST /livestream/{stream_id}/end/`

**Headers:**

```json
{
  "Authorization": "Bearer YOUR_ACCESS_TOKEN",
  "Content-Type": "application/json"
}
```

**Response (200):**

```json
{
  "success": true,
  "message": "Stream ended",
  "duration_minutes": 45.5,
  "peak_viewers": 150
}
```

**Error Response (403):**

```json
{
  "error": "Unauthorized"
}
```

**Purpose:**

- Host stream শেষ করতে এই API call করবে
- Total duration ও peak viewers পাবে

---

### 4. **Get Active Live Streams**

**Endpoint:** `GET /livestream/active/`

**Response (200):**

```json
{
    "success": true,
    "message": "Active live streams fetched",
    "data": [
        {
            "id": 11,
            "seller_name": "nebadcen5372",
            "product_name": "Ikea Hemnes Bed Frame",
            "title": "HP Spectre x360",
            "description": "Watch live unboxing!",
            "status": "live",
            "room_name": "room_AmLlzyGgC9gBXy_RBNjZJg",
            "scheduled_at": "2025-12-24T09:12:50.562553Z",
            "started_at": "2025-12-24T09:12:50.568982Z",
            "ended_at": null,
            "viewer_count": 0,
            "peak_viewers": 0,
            "created_at": "2025-12-24T09:12:50.562971Z",
            "updated_at": "2025-12-24T09:12:50.569058Z",
            "product": 6,
            "seller": 9
        }
    ]
}
```

**Purpose:**

- সব active live streams দেখতে
- Homepage এ list দেখানোর জন্য

---

### 5. **Get My Streams** (Host)

**Endpoint:** `GET /livestream/my_livestream/`

**Headers:**

```json
{
  "Authorization": "Bearer YOUR_ACCESS_TOKEN"
}
```

**Query Parameters:**

- `status` (optional): `live`, `ended`, `scheduled`

**Example:** `GET /livestream/my_livestream/?status=live`

**Response (200):**

```json
[
  {
    "id": 10,
    "title": "My Live Stream",
    "status": "live",
    "viewer_count": 25,
    "peak_viewers": 30,
    "started_at": "2025-12-24T09:05:19.334471Z",
    "room_name": "room_3aAiu_Z2fwoDyuxa5IJKnA"
  }
]
```

**Purpose:**

- Host নিজের সব streams দেখতে পারবে
- Dashboard এর জন্য

---

### 6. **Get Stream Comments**

**Endpoint:** `GET /livestream/{stream_id}/comments/`

**Response (200):**

```json
[
  {
    "id": 1,
    "username": "user123",
    "message": "Great product!",
    "created_at": "2025-12-24T09:10:00.000000Z"
  },
  {
    "id": 2,
    "username": "buyer456",
    "message": "How much is it?",
    "created_at": "2025-12-24T09:11:30.000000Z"
  }
]
```

**Purpose:**

- Previous comments load করতে

---

## 🔌 WebSocket Events

### WebSocket Connection

**URL:** `ws://localhost:8000/ws/live/{stream_id}/`

**Example:** `ws://localhost:8000/ws/live/10/`

---

### **Connect করার নিয়ম:**

```javascript
const streamId = 10;
const socket = new WebSocket(`ws://localhost:8000/ws/live/${streamId}/`);

// Connection open
socket.onopen = () => {
  console.log("WebSocket connected");
};

// Receive messages
socket.onmessage = (event) => {
  const data = JSON.parse(event.data);
  console.log("Received:", data);
};

// Connection close
socket.onclose = () => {
  console.log("WebSocket disconnected");
};

// Error handling
socket.onerror = (error) => {
  console.error("WebSocket error:", error);
};
```

---

### **1. Send Chat Message**

**Client → Server:**

```json
{
  "type": "chat_message",
  "message": "Hello everyone!"
}
```

**Server → All Clients:**

```json
{
  "type": "chat_message",
  "message": "Hello everyone!",
  "username": "user123",
  "timestamp": "2025-12-24T09:15:00.000000Z"
}
```

**JavaScript Example:**

```javascript
// Send message
function sendMessage(message) {
  socket.send(
    JSON.stringify({
      type: "chat_message",
      message: message,
    })
  );
}

// Receive message
socket.onmessage = (event) => {
  const data = JSON.parse(event.data);
  if (data.type === "chat_message") {
    console.log(`${data.username}: ${data.message}`);
    // UI তে message show করুন
  }
};
```

---

### **2. Viewer Count Update**

**Server → All Clients (Auto):**

```json
{
  "type": "viewer_count",
  "count": 25
}
```

**কখন আসবে:**

- নতুন viewer join করলে
- কোন viewer leave করলে

**JavaScript Example:**

```javascript
socket.onmessage = (event) => {
  const data = JSON.parse(event.data);
  if (data.type === "viewer_count") {
    console.log(`Viewers: ${data.count}`);
    // UI তে viewer count update করুন
  }
};
```

---

### **3. Stream Status Update**

**Server → All Clients:**

```json
{
  "type": "stream_status",
  "status": "ended",
  "message": "Stream has ended"
}
```

**কখন আসবে:**

- Host stream end করলে
- Stream এ কোন সমস্যা হলে

**JavaScript Example:**

```javascript
socket.onmessage = (event) => {
  const data = JSON.parse(event.data);
  if (data.type === "stream_status") {
    if (data.status === "ended") {
      alert("Stream has ended");
      // Redirect করুন বা UI update করুন
    }
  }
};
```

---

### **4. Error Messages**

**Server → Client:**

```json
{
  "type": "error",
  "message": "Invalid JSON format"
}
```

**JavaScript Example:**

```javascript
socket.onmessage = (event) => {
  const data = JSON.parse(event.data);
  if (data.type === "error") {
    console.error("Error:", data.message);
  }
};
```

---

## 🚀 Complete Integration Guide

### **Host এর Complete Flow:**

```javascript
// Step 1: Create & Start Stream
async function startLiveStream(productId, title) {
  const response = await fetch("http://localhost:8000/livestream/", {
    method: "POST",
    headers: {
      Authorization: `Bearer ${accessToken}`,
      "Content-Type": "application/json",
    },
    body: JSON.stringify({
      product_id: productId,
      title: title,
      description: "My product demo",
    }),
  });

  const data = await response.json();
  const streamId = data.stream.id;
  const livekit = data.livekit;

  // Step 2: Connect to LiveKit
  await connectToLiveKit(livekit.url, livekit.token);

  // Step 3: Connect to WebSocket for chat
  connectWebSocket(streamId);

  return streamId;
}

// Step 4: End Stream
async function endStream(streamId) {
  await fetch(`http://localhost:8000/livestream/${streamId}/end/`, {
    method: "POST",
    headers: {
      Authorization: `Bearer ${accessToken}`,
    },
  });
}
```

---

### **Viewer এর Complete Flow:**

```javascript
// Step 1: Join Stream
async function joinLiveStream(streamId) {
  const response = await fetch(
    `http://localhost:8000/livestream/${streamId}/join/`
  );
  const data = await response.json();

  if (!data.success) {
    alert("Stream is not live");
    return;
  }

  // Step 2: Connect to LiveKit
  await connectToLiveKit(data.livekit_url, data.token);

  // Step 3: Connect to WebSocket for chat
  connectWebSocket(streamId);
}

// WebSocket Connection
function connectWebSocket(streamId) {
  const socket = new WebSocket(`ws://localhost:8000/ws/live/${streamId}/`);

  socket.onmessage = (event) => {
    const data = JSON.parse(event.data);

    switch (data.type) {
      case "chat_message":
        addMessageToUI(data.username, data.message);
        break;
      case "viewer_count":
        updateViewerCount(data.count);
        break;
      case "stream_status":
        if (data.status === "ended") {
          alert("Stream ended");
        }
        break;
    }
  };

  return socket;
}

// Send Chat Message
function sendChatMessage(socket, message) {
  socket.send(
    JSON.stringify({
      type: "chat_message",
      message: message,
    })
  );
}
```

---

## 📝 Example Code

### **Complete React Component:**

```javascript
import React, { useState, useEffect, useRef } from "react";

function LiveStreamPage({ streamId, isHost }) {
  const [viewerCount, setViewerCount] = useState(0);
  const [messages, setMessages] = useState([]);
  const [inputMessage, setInputMessage] = useState("");
  const socketRef = useRef(null);

  useEffect(() => {
    // Join or create stream
    if (isHost) {
      createStream();
    } else {
      joinStream();
    }

    // Connect WebSocket
    connectWebSocket();

    return () => {
      if (socketRef.current) {
        socketRef.current.close();
      }
    };
  }, []);

  const createStream = async () => {
    const res = await fetch("/livestream/", {
      method: "POST",
      headers: {
        Authorization: `Bearer ${token}`,
        "Content-Type": "application/json",
      },
      body: JSON.stringify({
        product_id: 1,
        title: "My Stream",
      }),
    });
    const data = await res.json();
    // Connect to LiveKit with data.livekit
  };

  const joinStream = async () => {
    const res = await fetch(`/livestream/${streamId}/join/`);
    const data = await res.json();
    // Connect to LiveKit with data.livekit_url and data.token
  };

  const connectWebSocket = () => {
    const ws = new WebSocket(`ws://localhost:8000/ws/live/${streamId}/`);
    socketRef.current = ws;

    ws.onmessage = (event) => {
      const data = JSON.parse(event.data);

      if (data.type === "chat_message") {
        setMessages((prev) => [...prev, data]);
      } else if (data.type === "viewer_count") {
        setViewerCount(data.count);
      }
    };
  };

  const sendMessage = () => {
    if (inputMessage.trim() && socketRef.current) {
      socketRef.current.send(
        JSON.stringify({
          type: "chat_message",
          message: inputMessage,
        })
      );
      setInputMessage("");
    }
  };

  return (
    <div>
      <div>Viewers: {viewerCount}</div>
      <div>
        {messages.map((msg, i) => (
          <div key={i}>
            <strong>{msg.username}:</strong> {msg.message}
          </div>
        ))}
      </div>
      <input
        value={inputMessage}
        onChange={(e) => setInputMessage(e.target.value)}
        onKeyPress={(e) => e.key === "Enter" && sendMessage()}
      />
      <button onClick={sendMessage}>Send</button>
    </div>
  );
}
```

---

## 🎯 Summary

### **Host করবে:**

1. `POST /livestream/` - Stream create ও start
2. LiveKit connect করবে (response এর token দিয়ে)
3. WebSocket connect করবে chat এর জন্য
4. `POST /livestream/{id}/end/` - Stream শেষ করতে

### **Viewer করবে:**

1. `GET /livestream/{id}/join/` - Stream join করতে
2. LiveKit connect করবে (response এর token দিয়ে)
3. WebSocket connect করবে chat এর জন্য

### **WebSocket Events:**

- **Send:** `chat_message` - Message পাঠাতে
- **Receive:** `chat_message` - নতুন message
- **Receive:** `viewer_count` - Viewer count update
- **Receive:** `stream_status` - Stream status change

---

## 🔒 Authentication

**Token পাওয়ার জন্য:**

```bash
POST /auth/login/
Body: {"username": "user", "password": "pass"}
Response: {"access": "token"}
```

**Header এ ব্যবহার:**

```
Authorization: Bearer YOUR_ACCESS_TOKEN
```

---

এই documentation follow করে complete live streaming system implement করতে পারবেন! 🎉
