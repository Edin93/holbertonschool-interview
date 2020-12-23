#!/usr/bin/python3
"""
This module contains a recursive function that queries the Reddit API,
parses the title of all hot articles, and prints a sorted count of
given keywords (case-insensitive, delimited by spaces. Javascript should
count as javascript, but java should not).
"""
import requests


def count_words(subreddit, word_list, after=None):
	"""
		Queries the Reddit API, parses the title of all hot articles, and
		prints a sorted count of given keywords (case-insensitive, delimited
		by spaces. Javascript should count as javascript, but java should not).
	"""
	sub = subreddit.lower()
	words = [w.lower() for w in word_list]
	print(words)
	params = {'limit': 100}
	url = 'https://www.reddit.com/r/{}/hot'.format(sub)

	r = requests.get(url, params=params, allow_redirects=False)
	data = r.json()
	print(data)
	# data = r.json().get('data').get('children')
	# print(data)