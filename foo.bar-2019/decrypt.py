import base64

MESSAGE = 'GksfEA0ABAdLEhAPEBUGHgkEGkRNVB9WX1lcVwALGQBJQ1tUH1BDQVVXDAkIQkJDRhFeU19HREFG TFZFSQoPF0pQVFxSXgRLQEVJAgIcUVBGUF1XDxhLRVRDRgFWWV9WW1cFS0BFSREAFlpcREYXEltM SxYPBQRTFBUXU19dRkxWRUkUCBoZEk0='

KEY = 'allencat850502'

result = []
for i, c in enumerate(base64.b64decode(MESSAGE)):
    result.append(chr(ord(c) ^ ord(KEY[i % len(KEY)])))

print(''.join(result))
