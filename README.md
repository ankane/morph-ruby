# Morph Ruby

[Morph](https://github.com/ankane/morph) client for Ruby

[![Build Status](https://github.com/ankane/morph-ruby/workflows/build/badge.svg?branch=master)](https://github.com/ankane/morph-ruby/actions)

## Installation

First, [install Morph](https://github.com/ankane/morph#building-from-source). For Homebrew, use:

```sh
brew install ankane/brew/morph
```

Add these lines to your application’s Gemfile:

```ruby
gem 'morph-ruby'
```

## Getting Started

Create a client

```ruby
morph = Morph::Client.new
```

Generate a key pair

```ruby
morph.keygen
```

Set a key

```ruby
morph.set("hello", "world")
```

**Note:** Each key should only be set once, or the value will not be recoverable

Get a key

```ruby
morph.get("hello")
```

Delete all keys

```ruby
morph.flushall
```

Get the number of keys

```ruby
morph.dbsize
```

List keys

```ruby
morph.keys("*")
```

Get info

```ruby
morph.info
```

## History

View the [changelog](https://github.com/ankane/morph-ruby/blob/master/CHANGELOG.md)

## Contributing

Everyone is encouraged to help improve this project. Here are a few ways you can help:

- [Report bugs](https://github.com/ankane/morph-ruby/issues)
- Fix bugs and [submit pull requests](https://github.com/ankane/morph-ruby/pulls)
- Write, clarify, or fix documentation
- Suggest or add new features

To get started with development:

```sh
git clone https://github.com/ankane/morph-ruby.git
cd morph-ruby
bundle install
bundle exec rake compile
bundle exec rake test
```
