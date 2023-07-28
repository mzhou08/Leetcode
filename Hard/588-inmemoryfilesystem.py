class TrieNode:
    def __init__(self, name):
        self.name = name        # file or dir name
        self.content = None  # file content, if exists
        self.children = {}

    def addContent(self, content):
        if self.content is None:
            self.content = ""

        self.content += content

    def addChild(self, child):
        self.children[child.name] = child

    def listChildren(self):
        if self.content is not None:
            return [self.name]

        return list(self.children.keys())

    def readContent(self):
        return self.content
    

class Trie:
    def __init__(self, rootNode: TrieNode):
        self.root = rootNode

    def followPath(self, path: list[str]):
        currNode = self.root
        
        for segment in path:
            if segment not in currNode.children:
                newNode = TrieNode(segment)
                currNode.addChild(newNode)
                
            currNode = currNode.children[segment]

        return currNode

    def insert(self, path: list[str], content=None):
        currNode = self.followPath(path)
        
        if content is not None:
            # is an addContentToFile call
            currNode.addContent(content)

    def listChildren(self, path):
        currNode = self.followPath(path)

        return list(currNode.listChildren())

    def readContent(self, path):
        currNode = self.followPath(path)
        return currNode.readContent()

def _splitPath(path: str):
    if path == "/":
        return []
    else:
        return path.split("/")[1:]

class FileSystem:

    def __init__(self):
        root = TrieNode("")
        self.trie = Trie(root)

    def ls(self, path: str) -> List[str]:    
        children = self.trie.listChildren(_splitPath(path))
        return sorted(children)

    def mkdir(self, path: str) -> None:
        self.trie.insert(path=_splitPath(path))

    def addContentToFile(self, filePath: str, content: str) -> None:
        self.trie.insert(path=_splitPath(filePath), content=content)

    def readContentFromFile(self, filePath: str) -> str:
        return self.trie.readContent(path=_splitPath(filePath))
        


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.ls(path)
# obj.mkdir(path)
# obj.addContentToFile(filePath,content)
# param_4 = obj.readContentFromFile(filePath)