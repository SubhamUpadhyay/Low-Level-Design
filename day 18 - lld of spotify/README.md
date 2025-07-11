# Spotify-like Music Player in C++

## Overview

This is a modular, header-driven implementation of a Spotify-like music player in C++ that demonstrates:

- Audio playback through multiple output devices (Bluetooth, wired, etc.)
- Advanced playlist management with interchangeable playback strategies
- Implementation of key software design patterns
- Adherence to SOLID object-oriented design principles

---

## Features

### Audio Device Support
- Bluetooth Speaker implementation with connect/disconnect functionality
- Wired Headphones and Wireless Earbuds support
- Audio Device Manager to switch between connected devices
- Runtime device switching without interrupting playback

### Playlist Management
- Multiple Playback Strategies:
  - Sequential (default)
  - Shuffle/Random
  - Custom order
- Create and manage multiple playlists
- Add/remove songs from playlists dynamically
- Runtime switching between playback strategies

### Music Player Core
- Play, pause, resume functionality
- Next/previous song navigation
- Song library management
- User notification system (Observer pattern)

---

## Design Patterns Implemented

### 1. Singleton Pattern
- **Usage**: `AudioPlayer` class
- **Purpose**: Ensure only one instance of the core music player exists
- **Implementation**: Static `getInstance()` method provides global access

### 2. Observer Pattern
- **Usage**: User notifications
- **Purpose**: Decouple player state changes from notification logic
- **Implementation**:
  - `Subject` (e.g., `MusicPlayer`) maintains a list of `Observer`s (e.g., `User`)
  - When state changes occur, observers are notified

### 3. Strategy Pattern
- **Usage**: Playback strategies and audio output devices
- **Purpose**: Change behavior at runtime (e.g., shuffle vs. normal play)
- **Implementation**:
  - `PlaybackStrategy` interface with concrete implementations
  - `AudioDevice` interface to abstract physical device differences

### 4. Factory Pattern
- **Usage**: Audio device instantiation
- **Purpose**: Abstract away construction logic of complex device types
- **Implementation**: `AudioDeviceManager` acts as a factory and registry for available output devices

---

## SOLID Principles Applied

### Single Responsibility Principle
Each class has a focused responsibility:
- `Song` encapsulates song metadata
- `Playlist` handles song collection management
- `AudioDevice` abstracts device communication

### Open/Closed Principle
- New playback strategies or device types can be added without modifying core classes
- Core classes depend on interfaces, allowing seamless extension

### Liskov Substitution Principle
- All derived classes can substitute base class references
- E.g., any `AudioDevice` implementation can be passed to the music player

### Interface Segregation Principle
- Interfaces are small and targeted:
  - `Observer` only defines `update()`
  - `AudioDevice` defines only essential audio methods

### Dependency Inversion Principle
- High-level modules (like `AudioPlayer`) depend on abstractions (`IAudioOutput`, `IPlayStrategy`) rather than concrete classes

---

## Example Output

The application demonstrates:

- Audio device connection and switching in real time
- Multiple playlist playback modes (sequential, shuffle, etc.)
- Music control commands (play, pause, next, previous)
- Observer-based user notifications upon actions

---

## Future Enhancements

### Persistent Storage
- Save/load playlists and user library
- Remember previously connected devices

### Advanced Playback Features
- Crossfade transitions between songs
- Gapless playback
- Equalizer and audio filters

### Network Integration
- Stream songs from remote URLs
- Download for offline playback

### UI & UX Improvements
- Build a graphical interface (desktop or mobile)
- Add mobile gesture support or touch UI

### Extended Device Ecosystem
- Support for AirPlay, Chromecast
- Multi-room synchronized playback

---

## Why These Design Patterns?

| Pattern     | Reason |
|-------------|--------|
| Singleton   | Enforces a single point of control for audio playback, ensuring consistency and global access |
| Observer    | Cleanly separates user updates from core logic, allowing easy extension for notifications |
| Strategy    | Provides flexibility for dynamic behavior changes like playback mode or device routing |
| Factory     | Abstracts and simplifies the creation of new output device types, especially useful for third-party APIs |

---

## Summary

This implementation lays the groundwork for building a robust and extensible music player using proper software engineering practices. Each component is modular, testable, and designed with long-term maintainability in mind.
