require_relative "test_helper"

class ClientTest < Minitest::Test
  def test_works
    morph = Morph::Client.new
    morph.flushall
    morph.set("hello", "world")
    assert_equal "world", morph.get("hello")
    assert_nil morph.get("missing")
    assert_equal ["hello"], morph.keys("*")
    assert_equal 1, morph.dbsize
    assert_match "morph_version", morph.info
  end

  def test_keygen
    morph = Morph::Client.new
    Dir.chdir(Dir.mktmpdir) do
      morph.keygen
      assert File.exist?("morph.sk")
      assert File.exist?("morph.pk")
    end
  end
end
