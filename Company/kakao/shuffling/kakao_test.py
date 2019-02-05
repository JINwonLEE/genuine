import random

def Fisher_Yates_shuffle(song_list):
    length_ = len(song_list)
    end_ = length_ - 1
    for ending_ in range(end_, 0, -1):
        random_number = random.randint(0, ending)
        if ending_ == random_number:
            continue
        song_list[ending_], song_list[random_number] = song_list[random_number], song_list[ending_]
    return song_list

def GetRandomLength(total_length, sub_length):
    distance = 100 / sub_length
    rate = 1 / sub_length
    start_rate = (int)(rate * 10) * 10
    end_rate = start_rate + 10

    start_distance = start_rate * total_langth / 100
    end_distance = end_rate * total_length / 100

    dist_list = []
    if sub_length == 1:
        position = random.uniform(0, total_length)
        dist_list.append(position)
        return dist_list
 
    sum_length = 0
    for i in range(sub_length):
        rand_distance = random.uniform(start_distance, end_distance)
        if i == 0:
            position = rand_distance(0, total_length - end_distance * (sub_length - 1))
        else :
            position = sum_length + rand_distance

        sum_length = position
        dist_list.append(sum_length)

    return dist_list



test_case = input()
for _ in range((int)(test_case)):
    songs = input()
    singers = input()
    song_dict = {}

    song_list = songs.split("\t")
    singer_list = singers.split("\t")
    total_length = len(song_list)
    num_to_song = {}
    length_list = []


    for song, singer in zip(song_list, singer_list):
        if singer not in song_dict:
            song_dict[singer] = []
        song_dict[singer].append(song)

    for key in song_dict:
        tmp_song_list = song_dict[key]
        if len(tmp_song_list) > 1:
            tmp_song_list = Fisher_Yates_shuffle(tmp_song_list)
        length_list = GetRandomLength(total_length, len(tmp_song_list))
        for length_, song in zip(length_list, tmp_song_list):
            if str(length_) not in num_to_song:
                num_to_song[str(length_)] = song
            else:
                length_ += 0.00001
                num_to_song[str(length_)] = song
            length_list.append(length_)

    length_list = sorted(length_list)
    
    shuffle_list = ""
    for idx, length_ in enumerate(length_list):
        tmp_song = num_to_song[str(length_)]
        shuffle_list += tmp_song
        if idx != total_length - 1:
            shuffle_list += "\t"

    print(shuffle_list)





