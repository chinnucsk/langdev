package fogus {
  object PWD {
    val pwd = new java.io.File(".")

    def /(s:String) = {
      pwd.getCanonicalPath + s
    }
  }
}
