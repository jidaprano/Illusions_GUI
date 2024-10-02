Illusions GUI for COSI Illusions exhibit
Author: Joseph Daprano
        email: joseph.daprano@gmail.comm
        website: josephdaprano.com
        github: https://github.com/jidaprano
        linkedin: www.linkedin.com/in/jdaprano

This project was created in QT and verified with QT 6.5.1 and 6.5.3.

Required file structure:
    There is an example Content folder in the github repository for this project that accurately represents the required file structure.
    The executable MUST be in the same directory as the Content folder, which should have the following structure:
      - Content contains 2 files: Audio and Optical
      - Each of those 2 files contain:
        - A series of folders, each of which contain the illusion and a text file with the illusion explanation written in it. THE NAME OF EACH FOLDER DETERMINES THE NAME OF THE ILLUSION IN THE EXHIBIT
                - In the Optical folder, the illusion may be a folder containing an image sequence, a single image, or a video in one of the following formats: mp4, mov, m4v
                - In the Audio folder, the illusion may be an audio file in one of the following formats: mp3, ogg, WAV, wav
                - The text file should have the suffix .txt
                        - Each text file should have two lines in it: the first line is the question text displayed before the "Reveal explanation" button is pressed, and the second line is the actual explanation text
                        - If not all of the explanation text shows up in the exhibit, it is possible that it is too long. The font size does not scale down in the exhibit, so if the text is too long some will be cut off.
        - A file called ButtonIcons that contains image files corresponding to each of the illusions
                - The image file must be in the .jpg format
                - The name of the image file MUST be the same as the name of the illusion it corresponds to (as defined in the name of the folder the illusion is stored in)
