#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <random>
#include <ctime>

using namespace std;
// ==================== Observer Pattern ====================
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const string& message) = 0;
};

class Subject {
public:
    virtual ~Subject() = default;
    virtual void subscribe(Observer* observer) = 0;
    virtual void unsubscribe(Observer* observer) = 0;
    virtual void notify(const string& message) = 0;
};

// ==================== Audio Device Support ====================
class AudioDevice {
public:
    virtual ~AudioDevice() = default;
    virtual void connect() = 0;
    virtual void disconnect() = 0;
    virtual void playAudio(const string& song) = 0;
    virtual string getDeviceName() const = 0;
};

class BluetoothSpeaker : public AudioDevice {
public:
    BluetoothSpeaker(const string& name) : deviceName(name), connected(false) {}
    
    void connect() override {
        connected = true;
        cout << "Connected to Bluetooth speaker: " << deviceName << endl;
    }
    
    void disconnect() override {
        connected = false;
        cout << "Disconnected from Bluetooth speaker: " << deviceName << endl;
    }
    
    void playAudio(const string& song) override {
        if (connected) {
            cout << "Playing [" << song << "] on Bluetooth speaker: " << deviceName << endl;
        } else {
            cout << "Error: Bluetooth speaker not connected!" << endl;
        }
    }
    
    string getDeviceName() const override {
        return deviceName;
    }

private:
    string deviceName;
    bool connected;
};

class WiredHeadphones : public AudioDevice {
public:
    WiredHeadphones(const string& name) : deviceName(name), connected(false) {}
    
    void connect() override {
        connected = true;
        cout << "Connected to wired headphones: " << deviceName << endl;
    }
    
    void disconnect() override {
        connected = false;
        cout << "Disconnected from wired headphones: " << deviceName << endl;
    }
    
    void playAudio(const string& song) override {
        if (connected) {
            cout << "Playing [" << song << "] on wired headphones: " << deviceName << endl;
        } else {
            cout << "Error: Headphones not connected!" << endl;
        }
    }
    
    string getDeviceName() const override {
        return deviceName;
    }

private:
    string deviceName;
    bool connected;
};

// ==================== Audio Device Manager ====================
class AudioDeviceManager {
public:
    void addDevice(unique_ptr<AudioDevice> device) {
        devices.push_back(move(device));
    }
    
    AudioDevice* getCurrentDevice() const {
        if (currentDeviceIndex >= 0 && currentDeviceIndex < devices.size()) {
            return devices[currentDeviceIndex].get();
        }
        return nullptr;
    }
    
    void switchDevice(int index) {
        if (index >= 0 && index < devices.size()) {
            if (currentDeviceIndex >= 0 && currentDeviceIndex < devices.size()) {
                devices[currentDeviceIndex]->disconnect();
            }
            currentDeviceIndex = index;
            devices[currentDeviceIndex]->connect();
        }
    }
    
    void liices() const {
        cout << "Available Audio Devices:" << endl;
        for (size_t i = 0; i < devices.size(); ++i) {
            cout << i << ": " << devices[i]->getDeviceName() 
                      << (i == currentDeviceIndex ? " (Current)" : "") << endl;
        }
    }

private:
    vector<unique_ptr<AudioDevice>> devices;
    int currentDeviceIndex = -1;
};

// ==================== Song Class ====================
class Song {
public:
    Song(const string& title, const string& artist, int durationSec)
        : title(title), artist(artist), durationSec(durationSec) {}
    
    string getTitle() const { return title; }
    string getArtist() const { return artist; }
    int getDuration() const { return durationSec; }
    
    string getFormattedDuration() const {
        int minutes = durationSec / 60;
        int seconds = durationSec % 60;
        
        ostringstream oss;
        oss << setw(2) << setfill('0') << minutes << ":"
            << setw(2) << setfill('0') << seconds;
        return oss.str();
    }

private:
    string title;
    string artist;
    int durationSec;
};

// ==================== Playback Strategy ====================
class PlaybackStrategy {
public:
    virtual ~PlaybackStrategy() = default;
    virtual void play(const vector<Song>& playlist) = 0;
    virtual string getStrategyName() const = 0;
};

class SequentialPlayback : public PlaybackStrategy {
public:
    void play(const vector<Song>& playlist) override {
        cout << "Playing sequentially:" << endl;
        for (const auto& song : playlist) {
            cout << "▶ " << song.getTitle() << " - " << song.getArtist() 
                      << " [" << song.getFormattedDuration() << "]" << endl;
        }
    }
    
    string getStrategyName() const override {
        return "Sequential";
    }
};

class RandomPlayback : public PlaybackStrategy {
public:
    void play(const vector<Song>& playlist) override {
        cout << "Playing randomly:" << endl;
        
        // Create a shuffled copy of the playlist
        vector<Song> shuffled = playlist;
        shuffle(shuffled.begin(), shuffled.end(), mt19937(random_device()()));
        
        for (const auto& song : shuffled) {
            cout << "🔀 " << song.getTitle() << " - " << song.getArtist() 
                      << " [" << song.getFormattedDuration() << "]" << endl;
        }
    }
    
    string getStrategyName() const override {
        return "Random";
    }
};

class CustomOrderPlayback : public PlaybackStrategy {
public:
    CustomOrderPlayback(const vector<int>& order) : customOrder(order) {}
    
    void play(const vector<Song>& playlist) override {
        cout << "Playing custom order:" << endl;
        
        for (int index : customOrder) {
            if (index >= 0 && index < playlist.size()) {
                const auto& song = playlist[index];
                cout << "🎵 " << song.getTitle() << " - " << song.getArtist() 
                          << " [" << song.getFormattedDuration() << "]" << endl;
            }
        }
    }
    
    string getStrategyName() const override {
        return "Custom";
    }

private:
    vector<int> customOrder;
};

// ==================== Playlist Class ====================
class Playlist {
public:
    Playlist(const string& name) : name(name), currentStrategy(make_unique<SequentialPlayback>()) {}
    
    void addSong(const Song& song) {
        songs.push_back(song);
    }
    
    void removeSong(const string& songTitle) {
        songs.erase(
            remove_if(songs.begin(), songs.end(),
                [&songTitle](const Song& song) { return song.getTitle() == songTitle; }),
            songs.end()
        );
    }
    
    void play() {
        currentStrategy->play(songs);
    }
    
    void setPlaybackStrategy(unique_ptr<PlaybackStrategy> strategy) {
        currentStrategy = move(strategy);
    }
    
    string getName() const {
        return name;
    }
    
    int getSongCount() const {
        return songs.size();
    }
    
    const vector<Song>& getSongs() const {
        return songs;
    }

private:
    string name;
    vector<Song> songs;
    unique_ptr<PlaybackStrategy> currentStrategy;
};

// ==================== Music Player ====================
class MusicPlayer : public Subject {
public:
    // Singleton implementation
    static MusicPlayer& getInstance() {
        static MusicPlayer instance;
        return instance;
    }
    
    // Delete copy constructor and assignment operator
    MusicPlayer(const MusicPlayer&) = delete;
    void operator=(const MusicPlayer&) = delete;
    
    // Player functionality
    void playSong(const Song& song) {
        currentSong = &song;
        isPlaying = true;
        if (audioDeviceManager.getCurrentDevice()) {
            audioDeviceManager.getCurrentDevice()->playAudio(song.getTitle());
        }
        notify("Now playing: " + song.getTitle() + " by " + song.getArtist());
    }
    
    void pause() {
        if (currentSong && isPlaying) {
            isPlaying = false;
            notify("Paused: " + currentSong->getTitle());
        }
    }
    
    void resume() {
        if (currentSong && !isPlaying) {
            isPlaying = true;
            if (audioDeviceManager.getCurrentDevice()) {
                audioDeviceManager.getCurrentDevice()->playAudio(currentSong->getTitle());
            }
            notify("Resumed: " + currentSong->getTitle());
        }
    }
    
    void nextSong() {
        if (!playlists.empty() && !playlists[currentPlaylistIndex]->getSongs().empty()) {
            // Simplified - in real implementation would use current playback strategy
            currentSongIndex = (currentSongIndex + 1) % playlists[currentPlaylistIndex]->getSongs().size();
            playSong(playlists[currentPlaylistIndex]->getSongs()[currentSongIndex]);
        }
    }
    
    void previousSong() {
        if (!playlists.empty() && !playlists[currentPlaylistIndex]->getSongs().empty()) {
            currentSongIndex = (currentSongIndex - 1 + playlists[currentPlaylistIndex]->getSongs().size()) 
                              % playlists[currentPlaylistIndex]->getSongs().size();
            playSong(playlists[currentPlaylistIndex]->getSongs()[currentSongIndex]);
        }
    }
    
    // Library management
    void addSongToLibrary(const Song& song) {
        library.push_back(song);
        notify("Added to library: " + song.getTitle());
    }
    
    void removeSongFromLibrary(const string& songTitle) {
        library.erase(
            remove_if(library.begin(), library.end(),
                [&songTitle](const Song& song) { return song.getTitle() == songTitle; }),
            library.end()
        );
        notify("Removed from library: " + songTitle);
    }
    
    // Playlist management
    void addPlaylist(unique_ptr<Playlist> playlist) {
        playlists.push_back(move(playlist));
        notify("Added playlist: " + playlists.back()->getName());
    }
    
    void removePlaylist(const string& playlistName) {
        playlists.erase(
            remove_if(playlists.begin(), playlists.end(),
                [&playlistName](const unique_ptr<Playlist>& playlist) {
                    return playlist->getName() == playlistName;
                }),
            playlists.end()
        );
        notify("Removed playlist: " + playlistName);
    }
    
    void playPlaylist(const string& playlistName) {
        auto it = find_if(playlists.begin(), playlists.end(),
            [&playlistName](const unique_ptr<Playlist>& p) {
                return p->getName() == playlistName;
            });
        
        if (it != playlists.end()) {
            currentPlaylistIndex = distance(playlists.begin(), it);
            currentSongIndex = 0;
            (*it)->play();
            playSong((*it)->getSongs()[currentSongIndex]);
        }
    }
    
    void setPlaybackStrategyForCurrentPlaylist(unique_ptr<PlaybackStrategy> strategy) {
        if (currentPlaylistIndex >= 0 && currentPlaylistIndex < playlists.size()) {
            playlists[currentPlaylistIndex]->setPlaybackStrategy(move(strategy));
        }
    }
    
    // Audio device management
    AudioDeviceManager& getAudioDeviceManager() {
        return audioDeviceManager;
    }
    
    // Observer pattern implementation
    void subscribe(Observer* observer) override {
        observers.push_back(observer);
    }
    
    void unsubscribe(Observer* observer) override {
        observers.erase(
            remove(observers.begin(), observers.end(), observer),
            observers.end()
        );
    }
    
    void notify(const string& message) override {
        for (Observer* observer : observers) {
            observer->update(message);
        }
    }

private:
    MusicPlayer() {
        // Initialize with some default audio devices
        audioDeviceManager.addDevice(make_unique<BluetoothSpeaker>("JBL Flip 5"));
        audioDeviceManager.addDevice(make_unique<WiredHeadphones>("Sony WH-1000XM4"));
        audioDeviceManager.switchDevice(0); // Connect to first device by default
    }
    
    ~MusicPlayer() = default;
    
    vector<Observer*> observers;
    vector<Song> library;
    vector<unique_ptr<Playlist>> playlists;
    AudioDeviceManager audioDeviceManager;
    
    // Current playback state
    const Song* currentSong = nullptr;
    bool isPlaying = false;
    int currentPlaylistIndex = -1;
    int currentSongIndex = -1;
};

// ==================== User Class ====================
class User : public Observer {
public:
    User(const string& name) : name(name) {}
    
    void update(const string& message) override {
        cout << "[" << name << "] Notification: " << message << endl;
    }

private:
    string name;
};

// ==================== Main Function ====================
int main() {
    // Create music player (Singleton)
    MusicPlayer& player = MusicPlayer::getInstance();
    
    // Create users
    User user1("Alice");
    User user2("Bob");
    
    // Subscribe users to player updates
    player.subscribe(&user1);
    player.subscribe(&user2);
    
    // Create songs
    Song song1("Blinding Lights", "The Weeknd", 200);
    Song song2("Save Your Tears", "The Weeknd", 215);
    Song song3("Levitating", "Dua Lipa", 218);
    Song song4("Don't Start Now", "Dua Lipa", 183);
    Song song5("Watermelon Sugar", "Harry Styles", 174);
    
    // Add songs to library
    player.addSongToLibrary(song1);
    player.addSongToLibrary(song2);
    player.addSongToLibrary(song3);
    player.addSongToLibrary(song4);
    player.addSongToLibrary(song5);
    
    // Create playlists
    auto weeklyMix = make_unique<Playlist>("Weekly Mix");
    weeklyMix->addSong(song1);
    weeklyMix->addSong(song3);
    weeklyMix->addSong(song5);
    
    auto favorites = make_unique<Playlist>("Favorites");
    favorites->addSong(song2);
    favorites->addSong(song4);
    
    // Add playlists to player
    player.addPlaylist(move(weeklyMix));
    player.addPlaylist(move(favorites));
    
    // List available audio devices
    player.getAudioDeviceManager().liices();
    
    // Switch to different audio device
    player.getAudioDeviceManager().switchDevice(1);
    
    // Play playlist with different strategies
    cout << "\n=== Playing with Sequential Strategy ===" << endl;
    player.playPlaylist("Weekly Mix");
    
    cout << "\n=== Playing with Random Strategy ===" << endl;
    player.setPlaybackStrategyForCurrentPlaylist(make_unique<RandomPlayback>());
    player.playPlaylist("Weekly Mix");
    
    cout << "\n=== Playing with Custom Strategy ===" << endl;
    player.setPlaybackStrategyForCurrentPlaylist(
        make_unique<CustomOrderPlayback>(vector<int>{2, 0, 1}));
    player.playPlaylist("Weekly Mix");
    
    // Play some songs
    player.nextSong();
    player.pause();
    player.resume();
    player.previousSong();
    
    return 0;
}