from rank_bm25 import BM25Okapi

corpus = [
    "Hello there good man!",
    "It is quite windy in London",
    "How is the weather today?"
]

tokenized_corpus = [doc.split(" ") for doc in corpus]
print(tokenized_corpus)

bm25 = BM25Okapi(tokenized_corpus)
print('bm25: ',bm25)

query = "windy London"
tokenized_query = query.split(" ")

doc_scores = bm25.get_scores(tokenized_query)
print('doc_scores: ', doc_scores)